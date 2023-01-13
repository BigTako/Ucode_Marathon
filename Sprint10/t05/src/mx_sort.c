#include "header.h"

bool ascending_p(t_agent * a, t_agent * b){
	return a->power > b->power;
}

bool ascending_s(t_agent * a, t_agent * b){
	return a->strength > b->strength;
}

bool ascending_n(t_agent * a, t_agent * b){
	return (mx_strcmp(a->name, b->name) > 0);
}

void swap_agents(t_agent * a, t_agent * b)
{
	t_agent temp = *a;
	*a = *b;
	*b = temp;
}

void mx_sort(t_agent ** arr, int size, bool(*f)(t_agent *, t_agent *))
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (f(arr[j], arr[j + 1])) {
               	swap_agents(arr[j], arr[j + 1]);		
            }
        }
    }
}


