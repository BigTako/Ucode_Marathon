#include "list.h"

void mx_pop_front(t_list **list){
	if (!list) return;
	else{
		t_list *temp = *list;
		(*list) = (*list)->next;
		free(temp);
	}
}


