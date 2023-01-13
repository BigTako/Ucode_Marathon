#ifndef LIST_UTILS
#define LIST_UTILS
#include <stdio.h>
#include <stdlib.h>
typedef struct s_list{
	void *data;
	struct s_list *next;
} t_list;
void mx_pop_front(t_list **list);
void mx_pop_back(t_list **list);
#endif


