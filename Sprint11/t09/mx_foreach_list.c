#include "list.h"

void mx_foreach_list(t_list *list, void(*f)(t_list *node))
{
	if (!list) return;
	t_list * temp = list;
	while(temp){
		f(temp);
		temp = temp->next;
	}
}


