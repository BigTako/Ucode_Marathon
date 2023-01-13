#include <stdio.h>
#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size);

int* mx_del_dup_arr(int* src, int src_size, int* dst_size)
{
    if (!src 
    		|| src_size < 0) return NULL;
    int* set = malloc(src_size * sizeof(int));
    int add;
    *dst_size = 0;
    for (int i = 0; i < src_size; i++)
    {
        add = 1;
        for (int j = 0; j < *dst_size ; j++)
            if (src[i] == set[j]) {
                add = 0;
                break;
            }
        if (add)
        {
            set[*dst_size] = src[i];
            (*dst_size)++;
        }
    }
    return set;
}


