#ifndef LIST_UTILS
#define LIST_UTILS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct s_list{
	void *data;
	struct s_list *next;
} t_list;
#endif


