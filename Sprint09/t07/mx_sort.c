#include <stdbool.h>

void swap_int(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void mx_sort(int *arr, int size, bool(*f)(int, int))
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (f(arr[j], arr[j + 1])) {
               	swap_int(&arr[j], &arr[j + 1]);		
            }
        }
    }
}


