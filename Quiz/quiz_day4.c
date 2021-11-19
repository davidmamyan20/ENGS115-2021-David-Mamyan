#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int element_type;
typedef int size_type;

struct array
{
    element_type* start;
    size_type size;
};

struct array* create(int s)
{
   struct array* a = (struct array*)malloc(sizeof(struct array));
   a->size = s;
   a->start = (element_type*)malloc(sizeof(element_type) * s);
   return a;
}

void reversed_order(struct array* a)
{
	int i;
	int j;
	for(i = 0; i < a->size; i++)
	{
		for (j = a->size; j >=0; j--)
		{
			a->start[i] = a->start[j];
		}
		printf("%d\n", a->start[j]);
	
	}
}

int main()
{
    int i = 0;
    struct array* a = create(8);
    for (i = 0; i < a->size; ++i) {
        printf("a[%d]=%d\n", i, a->start[i]);
    }
    reversed_order(a);
    return 0;
}
