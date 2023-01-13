#include "list.h"

void mx_pop_index(t_list **list, int index){
	if (!list) return;
	else if(index <= 0) mx_pop_front(list);
	else if(index == 1) mx_pop_front(&((*list)->next));
	else{
		int count = 0;
		int flag = 0;
		t_list * temp = *list;
		t_list * cur;
		while(temp->next->next){
			if ( ++count == index){
				cur = temp->next->next;
				free(temp->next);
				temp->next = cur;	
				flag = 1;
				break;
			}
			temp = temp->next;
		}
		if (!flag) mx_pop_back(&temp);
	}
}


