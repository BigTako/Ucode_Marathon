#include "list.h"

void mx_pop_back(t_list **list){
	t_list *temp = *list;
	if (!temp) return;
	else if (!temp->next){
		free(*list);
		*list = NULL;
	} else {
		while (temp->next->next) temp = temp->next;
		free(temp->next);
		temp->next = NULL;
	}
}


