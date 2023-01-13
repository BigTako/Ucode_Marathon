#include "list.h"

void mx_push_index(t_list **list, void *data, int index){
	if (!list || !*list) return;
	else if(index <= 0) mx_push_front(list, data);
	else{
		int count = 1;
		int flag = 0;
		t_list * temp = *list;
		t_list * adding;
		while(temp->next){
			if (count == index){
				adding = mx_create_node(data);
				adding->next = temp->next;
				temp->next = adding;
				flag = 1;
			}
			temp = temp->next;
			count++;
		}
		if (!flag) mx_push_back(&temp, data);
	}
}


