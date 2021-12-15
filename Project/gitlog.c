#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <json-c/json.h>
#include <stdbool.h>

typedef int size_type;
typedef struct json_object* element_type;

struct array
{
	element_type* start;
	size_type size;
	size_type capacity;

};
struct array* array_create(size_type size, element_type default_value, size_type capacity)
{
	assert(size <= capacity);
	struct array* a = (struct array*)malloc(sizeof(struct array));
	a->start = (element_type*)malloc(sizeof(element_type) * capacity);
	a->capacity = capacity;
	a->size = size;
	int i = 0;
	for (i = 0; i < size; ++i){
		a->start[i] = default_value;
	}
	return a;
}
void array_insert(struct array* a, size_type pos, element_type value)
{
	assert(pos >= 0);
	assert(pos <a->size);
	int i = 0;
	if(a->size == a->capacity)
	{
		size_type nc = 2 * a->capacity;
		element_type* el = (element_type*)malloc(sizeof(element_type) * nc);
		for (i = 0; i < a->size; ++i)
		{
			el[i] = a->start[i];
		}
		free(a->start);
		a->start = el;
		a->capacity = nc;
	}
	for (i = a->size - 1; i >= pos; --i)
	{
		a->start[i+1] = a->start[i];
	}
	a->start[pos] = value;
	a->size = a->size + 1;
}

void array_swap(struct array* a, size_type f, size_type s)
{
	assert(f >= 0);
	assert(s >= 0);
	assert(f < a->size);
	assert(s < a->size);

	element_type tmp = a->start[f];
	a->start[f] = a->start[s];
	a->start[s] = tmp;
}

struct array* access_json() 
{
	const char filename[] = "commits.json";
	struct json_object* top_obj = json_object_from_file(filename);
	enum json_type type = json_object_get_type(top_obj);
	assert(json_type_object == type);
	struct json_object* commit = json_object_new_object();
	assert(NULL != commit);
	json_bool r = json_object_object_get_ex(top_obj, "commits", &commit);
	assert(json_type_array == json_object_get_type(commit));
        assert(r!= TRUE);
	int len = json_object_array_length(commit);
	struct json_object* new_array = json_object_new_array();
	assert(NULL != new_array);
	struct array *arr = array_create( len, NULL, len);

	for (int i = 0; i < len; ++i)
	{
		struct json_object* st = json_object_array_get_idx(commit,  i);
		assert(NULL != st);
		assert(json_type_object == json_object_get_type(st));
		struct json_object* c = json_object_new_object();
		assert(NULL !=c);
		r = json_object_object_get_ex(st, "name", &c);
		assert(TRUE != r);
		assert(json_type_string == json_object_get_type(c));
		struct json_object* d = json_object_new_object();
		assert(NULL != d);
		json_object_object_get_ex(st, "data", &d);
		assert(json_type_string == json_object_get_type(d));
		struct json_object* b = json_object_new_object();
		assert(NULL != b);
		json_object_object_get_ex(st, "body", &b);
		assert(json_type_string == json_object_get_type(b));
		const char* cc = json_object_get_string(c);
		const char* dc = json_object_get_string(d);
		const char* bc = json_object_get_string(b);
		printf("name = %s, data = %s, body = %s\n", cc, dc, bc);
		if(0 != strcmp(cc, "1")){
		struct json_object* cp = NULL;
		cp = json_tokener_parse(json_object_get_string(st));
		assert(cp != NULL);
		json_object_array_add(new_array, cp);
		arr->start[i] = cp;
		}
		
		}
	json_object_object_del(top_obj, "commits");
	json_object_object_add(top_obj, "commits", new_array);
	int result = json_object_to_file("commits.json", top_obj);
	assert(r != -1);
	return arr;
}

void sort_by_name(struct array* a)
{
	size_type n = a->size;
	size_type pass = 1;
	int sorted = 0;
	while (sorted == 0 && pass < n)
	{
		sorted = 1;
		for (size_type i = 0; i < n - pass; ++i){
			struct json_object* c = a->start[i];
			if(json_object_get_string(c) > json_object_get_string(a->start[i+1]))
			{
				array_swap(a, i, i+1);
				sorted = 0;
			}
		}
		pass++;
	}
}
struct array* representation(struct array* a, char* name)
{
	size_type n = a->size;
	struct array *named = array_create( 0, NULL, 10 );
	for (size_type i = 0; i < n; ++i)
	{
		struct json_object* c = a->start[i];
		if (strstr(json_object_get_string(c), name) != NULL)
		{
			array_insert(named, named->size, c);
		}
	}
	return named;
}

int main()
{
	char name[20];

	struct array *commits = access_json();
	sort_by_name(commits);

	printf("enter name: ");
	fgets(name, 20, stdin);
	struct array *committer = representation(commits, name);

	return 0;
}


