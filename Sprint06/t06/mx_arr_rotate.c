void mx_swap_int(int *s1, int *s2)
{
    int s1_temp = *s1;
    *s1 = *s2;
    *s2 = s1_temp;
}

void mx_arr_rotate(int * arr, int size, int shift){
    	int sh_temp = shift;
    	if (shift < 0) sh_temp = -sh_temp;
	for (int i = 0; i < sh_temp; i++)
		if (shift > 0)
		    for (int j = size - 1; j >= 1; j--)
			    mx_swap_int(&arr[j], &arr[j - 1]);	 
	    	else 
	 	    for (int j = 0; j != size - 1; j++)
			    mx_swap_int(&arr[j], &arr[j + 1]);
}


