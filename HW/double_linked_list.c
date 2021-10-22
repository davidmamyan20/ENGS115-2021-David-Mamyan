#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

typedef int element_type;
typedef unsigned int size_type;

struct node
{
    element_type data;
    struct node* next;
    struct node* prev;
};

struct list
{
    struct node* start;
    struct node* end;
};

struct node* node_create(element_type data, struct node* n, struct node* p)
{
   struct node* ln = (struct node*)malloc(sizeof(struct node));
   ln->data = data;
   ln->next = n;
   ln->prev = p;
   return ln;
}

struct list* list_create()
{
   struct list* l = (struct list*)malloc(sizeof(struct list));
   l->start = NULL;
   l->end = NULL;
}

int list_empty(struct list* l)
{
    assert(NULL != l);
    return l->start == NULL;
}

size_type list_size(struct list* l)
{
   size_type length = 0;
   struct node* current = NULL;
   for (current = l->start; current != NULL; current = current->next) {
       ++length;
   }
   return length;
}

element_type list_at(struct list* l, size_type pos)
{
    assert(pos >= 0);
    assert(pos < list_size(l));
    size_type i = 0;
    struct node* current = l->start;
    while (i < pos) {
        current = current->next;
        ++i;
    }
    assert(i == pos);
    assert(current != NULL);
    return current->data;
}

void list_print(struct list* l)
{
   struct node* ptr = l->start;
   printf("list elements: [ ");
   while (ptr != NULL) {
      printf("%d ", ptr->data);
      ptr = ptr->next;
   }
   printf("]\n");
}

// insert new node at the first position
void list_push_front(struct list* l, element_type data)
{
    struct node* n = node_create(data, NULL, NULL);
    if (list_empty(l)) {
        assert(NULL == l->start);
        assert(NULL == l->end);
        l->end = n;
    } else {
        assert(NULL != l->start);
        assert(NULL == l->start->prev);
        l->start->prev = n;
        n->next = l->start;
    }
    l->start = n;
}

// insert new node at the last position
void list_push_back(struct list* l, element_type data)
{
    struct node* n = node_create(data, NULL, NULL);
    if (list_empty(l)) {
        assert(NULL == l->start);
        assert(NULL == l->end);
        l->start = n;
        l->end = n;
    } else {
        assert(NULL != l->end);
        assert(NULL == l->end->next);
        l->end->next = n;
        n->prev = l->end;
    }
    l->end = n;
}

// delete first node
void list_pop_front(struct list* l)
{
    assert(! list_empty(l));
    struct node* temp = l->start;
    if (l->start->next == NULL) {
        assert(l->start == l->end);
        l->end = NULL;
    } else {
        assert(l->start->next->prev == l->start);
        l->start->next->prev = NULL;
    }
    l->start = l->start->next;
    free(temp);
}

// delete node at the last location
void list_pop_back(struct list* l)
{
    assert(! list_empty(l));
    struct node* temp = l->end;
    if (l->start->next == NULL) {
        assert(l->start == l->end);
        l->start = NULL;
    } else {
        assert(l->end->prev->next == l->end);
        l->end->prev->next = NULL;
    }
    l->end = l->end->prev;
}

// get data of first node
element_type list_front(struct list* l)
{
    assert(! list_empty(l));
    assert(NULL != l->start);
    return l->start->data;
}

// get data of last node
element_type list_back(struct list* l)
{
    assert(! list_empty(l));
    assert(NULL != l->end);
    return l->end->data;
}

// delete a node at given position
void list_remove(struct list* l, size_type pos)
{
    assert(! list_empty(l));
    assert(pos >= 0);
    assert(pos < list_size(l));
    struct node* current = l->start;
    size_type i = 0;
    while (i < pos) {
        current = current->next;
        ++i;
    }
    assert(i == pos);
    assert(NULL != current);
    if (current == l->start) {
        list_pop_front(l);
    } else if (current == l->end) {
        list_pop_back(l);
    } else {
        assert(NULL != current->next);
        assert(NULL != current->prev);
        current->next->prev = current->prev;
        current->prev->next = current->next;
        free(current);
    }
}

void list_insert(struct list* l, element_type data, size_type pos)
{
    assert(pos >= 0);
    size_type n = list_size(l);
    assert(pos <= n);
    if (pos == 0) {
        list_push_front(l, data);
    } else if (pos == n) {
        list_push_back(l, data);
    } else {
        struct node* current = l->start;
        size_type i = 0;
        while (i < pos) {
            current = current->next;
            ++i;
        }
        assert(i == pos);
        assert(NULL != current);
        assert(NULL != current->next);
        assert(NULL != current->prev);
        struct node* n = node_create(data, current, current->prev);
        current->prev = n;
        n->prev->next = n;
    }
}

void list_clear(struct list* l)
{
    assert(NULL != l);
    while (! list_empty(l)) {
        list_pop_back(l);
    }
}

void list_delete(struct list* l)
{
    assert(NULL != l);
    list_clear(l);
    free(l);
}


void insertion_sort(struct list* l)
{
	size_type in = list_size(l) - 1;
	for(int i = 1; i <= in; ++i)
	{
		element_type el = list_at(l,i);
		element_type pos = i;
		while((pos > 0) && (list_at(l, pos - 1) > el))
		{
			list_insert(l, list_at(l, pos - 1), pos);
			--pos;
		}

		list_insert(l, el, pos);
	}

}


int main()
{
    int i = 0;
    struct list* l = list_create();
    assert(list_size(l) == 0);
    assert(list_empty(l));
    list_push_back(l, 3);
    list_push_back(l, 4);
    list_push_front(l, 2);
    list_push_front(l, 1);
    assert(list_size(l) == 4);
    assert(! list_empty(l));
    assert(list_front(l) == 1);
    assert(list_back(l) == 4);
    assert(list_at(l, 0) == 1);
    assert(list_at(l, 1) == 2);
    assert(list_at(l, 2) == 3);
    assert(list_at(l, 3) == 4);
    list_insert(l, 0, 0);
    assert(list_size(l) == 5);
    list_insert(l, 5, list_size(l));
    assert(list_size(l) == 6);
    list_insert(l, 100, 3);
    assert(list_size(l) == 7);
    assert(list_front(l) == 0);
    assert(list_back(l) == 5);
    assert(list_at(l, 0) == 0);
    assert(list_at(l, 1) == 1);
    assert(list_at(l, 2) == 2);
    assert(list_at(l, 3) == 100);
    assert(list_at(l, 4) == 3);
    assert(list_at(l, 5) == 4);
    assert(list_at(l, 6) == 5);
    list_print(l);
    list_remove(l, 3);
    assert(list_at(l, 2) == 2);
    assert(list_at(l, 3) == 3);
    list_remove(l, list_size(l) - 1);
    list_remove(l, 0);
    assert(list_size(l) == 4);
    assert(! list_empty(l));
    assert(list_front(l) == 1);
    assert(list_back(l) == 4);
    assert(list_at(l, 0) == 1);
    assert(list_at(l, 1) == 2);
    assert(list_at(l, 2) == 3);
    assert(list_at(l, 3) == 4);
    list_pop_front(l);
    list_pop_back(l);
    assert(list_size(l) == 2);
    assert(! list_empty(l));
    assert(list_front(l) == 2);
    assert(list_back(l) == 3);
    list_clear(l);
    assert(list_size(l) == 0);
    assert(list_empty(l));
    list_delete(l);
    return 0;
    insertion_sort(l);
    printf("%d", l);
}
