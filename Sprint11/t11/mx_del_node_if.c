#include "list.h"

void mx_del_node_if(t_list **list, void *del_data, bool(*cmp)(void*a, void*b)){
	if (!list) return;
	t_list * temp;
	t_list * t = *list;
	if (cmp(t->data, del_data)){
		*list = t->next;
		free(t);
	}
	for (t = *list; t->next; ){
		if (cmp(t->next->data, del_data)){
			temp = t->next->next;
			free(t->next);
			t->next = temp;
			continue;
		}
		t = t->next;
	}
}


