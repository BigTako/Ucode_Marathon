#include "list.h"

void mx_pop_front(t_list **list){
	t_list *temp = *list;
	if (!temp) return;
	else{
		(*list) = (*list)->next;
		free(temp);
	}
}


