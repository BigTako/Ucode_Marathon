#include "duplicate.h"

t_intarr * mx_snew(int * arr, int size)
{	
	t_intarr * t = malloc(sizeof(t_intarr));
	t->arr = arr;
	t->size = size;
	return t;
}

t_intarr *mx_del_dup_sarr(t_intarr *src)
{
    if (!src || 
    		!src->arr 
    			|| src->size < 0) return 0; 
    int add;
    t_intarr * t = mx_snew(malloc(src->size*sizeof(int)), 0);
    for (int i = 0; i < src->size; i++){
        add = 1;
        for (int j = 0; j < t->size ; j++)
            if (src->arr[i] == t->arr[j]) {
                add = 0;
                break;
            }
        if (add){
     	      t->arr[t->size] = src->arr[i];   	
     	      t->size++;
        }
    }
    return t;
}


