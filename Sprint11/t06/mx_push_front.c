#include "list.h"

void mx_push_front(t_list ** list, void *data){
	t_list * prev = mx_create_node(data);
	prev->next = *list;
	*list = prev;
}


