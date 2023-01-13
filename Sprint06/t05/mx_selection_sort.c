int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);

int mx_selection_sort(char **arr, int size)
{
	int i_min;
	int swaps = 0;
	int l1;
	int l2;
	for (int j = 0 ; j < size - 1; j++){
		i_min = j;
		for (int i = j + 1; i < size; i++){
			l1 = mx_strlen(arr[i]);
			l2 = mx_strlen(arr[i_min]);
			if (( l1 < l2) || ((l1 == l2) 
				&& mx_strcmp(arr[i], arr[i_min]) < 0))	
				i_min = i;
		}
		if (i_min != j) {
			swaps++;
			char * temp = arr[j];
			arr[j] = arr[i_min];
			arr[i_min] = temp;
		}
	}
	return swaps;
}


