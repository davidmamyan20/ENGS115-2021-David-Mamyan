// To compile: gcc -o exe single_linked_list.c
// To run: ./exe

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

typedef double element_type;
typedef int size_type;

struct node
{
    element_type data;
    struct node* next;
};

struct sl_list
{
    size_type size;
    struct node* start;
};

struct node* create_node(element_type default_value, struct node* l)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = default_value;
    n->next = l;
}

size_type list_size(struct sl_list* o)
{
    return o->size;
}

int list_empty(struct sl_list* o)
{
    return o->start == NULL;
}

size_type list_max_size(struct sl_list* o)
{
    //TODO
    return 0;
}

struct sl_list* list_create(size_type size, element_type default_value)
{
    struct sl_list* l = (struct sl_list*)malloc(sizeof(struct sl_list));
    l->start = NULL;
    l->size = 0;
    struct node* prev = NULL;
    for (int i = 0; i < size; ++i) {
        struct node* n = create_node(default_value, NULL);
        if (l->start == NULL) {
            assert(i == 0);
            l->start = n;
            assert(prev == NULL);
        } else {
            assert(prev != NULL);
            prev->next = n;
        }
        prev = n;
        ++l->size;
    }
    return l;
}

/*
void list_insert(struct sl_list* a, size_type pos, element_type value)
{
    assert(pos <= list_size(a));
    assert(pos >= 0);
    struct node* prev_node = NULL;
    struct node* pos_node = a->start;
    int i = 0;
    while (i < pos) {
        prev_node = pos_node;
        pos_node = pos_node->next;
        ++i;
    }
    assert(i == pos);
    assert(NULL == prev_node || prev_node->next == pos_node);
    struct node* n = create_node(value, pos_node);
    if (NULL != prev_node) {
        prev_node->next = n;
    } else {
        a->start = n;
    }
    ++a->size;
}
*/

void list_insert(struct sl_list* a, size_type pos, element_type value)
{
    assert(pos <= list_size(a));
    assert(pos >= 0);
    struct node* prev_node = NULL;
    int i = 0;
    while (i < pos) {
        if (prev_node == NULL) {
            prev_node = a->start;
        } else {
            prev_node = prev_node->next;
        }
        ++i;
    }
    assert(i == pos);
    struct node* n = create_node(value, NULL);
    if (NULL == prev_node) {
        n->next = a->start;
        a->start = n;
    } else {
        n->next = prev_node->next;
        prev_node->next = n;
    }
    ++a->size;
}

void list_remove(struct sl_list* o, element_type pos)
{
    int i = 0;
    struct node* prev_node = o->start;
   if (pos == 1)
   {
	  o->start = prev_node->next;
	  free(prev_node);
   }
   else
   {
	  for(i = 0; i < (pos-2); i++)
	  {
		 prev_node = prev_node->next;
	  }
	 struct node* tmp = prev_node->next;
	 prev_node->next = tmp->next;
	 free(tmp);
   } 
}

void list_print(struct sl_list* a)
{
    printf("list elements: \n");
    struct node* p = a->start;
    while (p != NULL) {
        printf("%f\n", p->data);
        p = p->next;
    }
}

int main()
{
    int i = 0;
    struct sl_list* l = list_create(4, 7);
    assert(list_size(l) == 4);
    list_print(l);
    int number = 6;
    for (i = 0; i < number; ++i) {
        list_insert(l, 0, i);
    }
    assert(list_size(l) == 10);
    list_print(l);
    number = 4;
    for (i = 0; i < number; ++i) {
        list_insert(l, list_size(l), i);
    }
    list_print(l);
    assert(list_size(l) == 14);
    list_insert(l, 7, 100);
    list_print(l);
    number = 5;
    for (i = 0; i < number; ++i) {
        list_remove(l, 0);
    }
    assert(list_size(l) == 9);
    list_print(l);
    return 0;
}
