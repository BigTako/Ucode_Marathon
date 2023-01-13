void swap_int(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void mx_sort_arr_int(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap_int(&arr[j], &arr[j + 1]);
}


