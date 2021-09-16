#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef double element_type;
typedef int size_type;

struct array
{
    element_type* start;
    size_type size;
};

size_type size(struct array* o)
{
    return o->size;
}

int empty(struct array* o)
{
    return (o->size == 0);
}

size_type max_size(struct array* o)
{
    return INT_MAX;
}

element_type access(struct array* o, int index)
{
    return o->start[index];
}

struct array* create(int s)
{
   struct array* a = (struct array*)malloc(sizeof(struct array));
   a->size = s;
   a->start = (element_type*)malloc(sizeof(element_type) * s);
   return a;
}

double insert(struct array* o)
{
	int position = 0;
	int value = 0;
	printf("Enter the value which you want to use");
	scanf("%d", &value);
	printf("Enter the postion from 0 to 33");
	scanf("%d", &position);
	return o -> start[position] = value;
}

int main()
{
    int i = 0;
    struct array* a = create(34);
    insert(a);
    for (i = 0; i < size(a); ++i) {
        printf("a[%d]=%f\n", i, access(a, i));
    }
    return 0;
}

    
