#include "playlist.h"

void swap_nums(t_list *a, t_list *b){
	void * temp = a->data;
	a->data = b->data;
	b->data = temp;
}

bool mx_by_name(void * a, void * b){
	t_song * s_a = a;
	t_song * s_b = b;
	return mx_strcmp(s_a->name, s_b->name) > 0;
}

bool mx_by_artist(void * a, void  * b){
	t_song * s_a = a;
	t_song * s_b = b;
	return mx_strcmp(s_a->artist, s_b->artist) > 0;
}

t_list *mx_sort_list(t_list *list, bool(*cmp)(void*a, void*b))
{
	t_list * init = list;  
	for (t_list * temp_i = list; temp_i; temp_i = temp_i->next) {
		for (t_list * temp_j = init; temp_j->next; temp_j = temp_j->next) {
			if (cmp(temp_j->data, temp_j->next->data))
				swap_nums(temp_j, temp_j->next);
		}
	}
	return list;
}


