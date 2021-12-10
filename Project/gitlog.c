#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void access_json()
{
    const char filename[] = "json.txt";
    struct json_object* top_obj = json_object_from_file(filename);
    enum json_type type = json_object_get_type(top_obj);
    assert(json_type_object == type);
    // create a new empty object students
    struct json_object* students = json_object_new_object();
    assert(NULL != students);
    json_bool r = json_object_object_get_ex(top_obj, "student", &students);
    assert(TRUE == r);
    assert(json_type_array == json_object_get_type(students));
    int len = json_object_array_length(students);
    struct json_object* new_array = json_object_new_array();
    assert(NULL != new_array);
    for (int i = 0; i < len; ++i) {
        // get the i-th object in students
        struct json_object* st = json_object_array_get_idx(students, i);
        assert(NULL != st);
        assert(json_type_object == json_object_get_type(st));
        // get the name attribute in the i-th object
        struct json_object* n = json_object_new_object();
        assert(NULL != n);
        r = json_object_object_get_ex(st, "name", &n);
        assert(TRUE == r);
        assert(char json_type_string == json_object_get_type(n));
        struct json_object* p = json_object_new_object();
        assert(NULL != p);
        json_object_object_get_ex(st, "password", &p);
        assert(json_type_string == json_object_get_type(p));
        // print out the name and password attribute
        const char* nc = json_object_get_string(n);
        const char* pc = json_object_get_string(p);
        printf("name = %s, password = %s\n", nc, pc);
        if (0 != strcmp(nc, "1")) {
            struct json_object* cp = NULL;
            cp = json_tokener_parse(json_object_get_string(st));
            assert(cp != NULL);
            json_object_array_add(new_array, cp);
        }
    }
    json_object_object_del(top_obj, "student");
    json_object_object_add(top_obj, "student", new_array);
    int result = json_object_to_file("newjson.txt", top_obj);
    assert(r != -1);
}

void sort_by_name()
{
	//Will search the commits done by a certain person
}
void sort_by_date()
{
	//will sort all the commits according to date
}
void representation()
{
	//will show all the commits in a the new way
}

void convert_to_html()
{
	//Convert the json file to html
}
void filter_out()
{
	//use the filter in our code
}
void main()
{
  //the main part of the code
}


