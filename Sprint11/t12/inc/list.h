#ifndef LIST_UTILS
#define LIST_UTILS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_list{
	void *data;
	struct s_list *next;
} t_list;

t_list * mx_create_node(void *data);
void mx_pop_front(t_list **list);
void mx_pop_back(t_list **list);
void mx_push_back(t_list **list, void *data);
void mx_pop_index(t_list **list, int index);
t_list *mx_sort_list(t_list *list, bool(*cmp)(void*a, void*b));
void mx_clear_list(t_list **list);
#endif
