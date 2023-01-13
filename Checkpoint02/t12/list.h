#ifndef LIST_UTILS
#define LIST_UTILS
#include <stdlib.h>
#include <stdio.h>
typedef struct s_list{
	void *data;
	struct s_list *next;
} t_list;
#endif


