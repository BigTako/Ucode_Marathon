#include "list.h"

void mx_clear_list(t_list **list){
	t_list * temp = *list;
	t_list * copy = temp;
	if(!list) return;
	while (temp){
		copy = temp->next;
		free(temp);
		temp = copy;
	}
	*list = temp;
}


