#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

typedef double element_type;
typedef int size_type;

struct array
{
    element_type* start;
    size_type size;
    size_type capacity;
};

size_type array_size(struct array* o)
{
    assert(NULL != o);
    return o->size;
}

size_type array_capacity(struct array* o)
{
    assert(NULL != o);
    return o->capacity;
}

int array_empty(struct array* o)
{
    return (o->size == 0);
}

size_type array_max_size(struct array* o)
{
    assert(NULL != o);
    return INT_MAX;
}

element_type array_access(struct array* o, size_type index)
{
    assert(NULL != o);
    assert(index >= 0);
    assert(index < o->size);
    return o->start[index];
}

void array_modify(struct array* o, size_type index, element_type value)
{
    assert(NULL != o);
    assert(index >= 0);
    assert(index < o->size);
    o->start[index] = value;
}

struct array* array_create(size_type size, element_type default_value,
                           size_type capacity)
{
    assert(capacity > 0);
    assert(size <= capacity);
    struct array* a = (struct array*)malloc(sizeof(struct array));
    a->start = (element_type*)malloc(sizeof(element_type) * capacity);
    a->capacity = capacity;
    a->size = size;
    int i = 0;
    for (i = 0; i < size; ++i) {
        a->start[i] = default_value;
    }
    return a;
}

void array_insert(struct array* a, size_type pos, element_type value)
{
    assert(pos >= 0);
    assert(pos <= a->size);
    int i = 0;
    if (a->size == a->capacity) {
        element_type nc = 2 * a->capacity;
        element_type* el = (element_type*)malloc(sizeof(element_type) * nc);
        for (i = 0; i < a->size; ++i) {
            el[i] = a->start[i];
        }
        free(a->start);
        a->start = el;
        a->capacity = nc;
    }
    for (i = a->size - 1; i >= pos; --i) {
        a->start[i + 1] = a->start[i];
    }
    a->start[pos] = value;
    a->size = a->size + 1;
}

void array_remove(struct array* o, element_type pos)
{
    assert(pos >= 0);
    assert(pos < o->size);
	for (int i = pos + 1; i < array_size(o); i++) {
		o->start[i - 1] = o->start[i];
	}
	--o->size;
}

void array_set_capacity(struct array* a, size_type new_capacity)
{
    assert(a->size <= new_capacity);
	element_type* b = (element_type*)malloc(sizeof(element_type) * new_capacity);
	for (int i = 0; i < a->size; ++i) {
		b[i] = a->start[i];
	}
    free(a->start);
	a->start = b;
    a->capacity = new_capacity;
}

void array_print(struct array* a)
{
    int i = 0;
    printf("array size=%d capacity=%d\n", array_size(a), array_capacity(a));
    for (i = 0; i < array_size(a); ++i) {
        printf("array[%d]=%f\n", i, array_access(a, i));
    }
}
void array_swap(struct array* a, size_type f, size_type s)
{
    assert(f >= 0);
    assert(s >= 0);
    assert(f < array_size(a));
    assert(s < array_size(a));
    element_type tmp = a->start[f];
    a->start[f] = a->start[s];
    a->start[s] = tmp;
}

size_type partition(struct array* o, size_type left, size_type right, size_type pivot)
{
    size_type leftPointer = left - 1;
    size_type rightPointer = right;

    while(array_access(o, leftPointer + 1) < pivot);
    while(rightPointer > 0 && array_access(o, rightPointer - 1) > pivot)
    if(leftPointer >= rightPointer)
    {
        break;
    }
    else
    {
        array_swap(o,leftPointer, rightPointer);
    }
    array_swap (o,leftPointer, right);
    return leftPointer;
}

void quick_sort(struct array* a, size_type right, size_type left)
{
    if (right < left)
    {
        return;
    }
    else
    {
        size_type pivot = array_access(a,right);
        size_type part = partition (a, left, right, pivot);
        quick_sort(a, left, part - 1);
        quick_sort(a, part + 1, right);
    }
}

int main()
{
    int i = 0;
    struct array* a = array_create(8,3,8);
    array_modify (a,0,8);
    array_modify (a,1,5);
    array_modify (a,2,3);
    array_modify (a,3,7);
    array_modify (a,4,2);
    array_modify (a,5,4);
    array_modify (a,6,6);
    array_modify (a,7,9);
    quick_sort(a,0,8);
    array_print(a);
    return 0;
}
