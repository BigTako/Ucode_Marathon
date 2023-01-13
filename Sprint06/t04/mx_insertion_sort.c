int mx_strlen(const char *s);

int mx_insertion_sort(char ** arr, int size)
{
	int shifts = 0;
	int j;
	for (int i = 0; i < size; i++){
		j = i;
		while (j > 0 
			&& mx_strlen(arr[j-1]) > mx_strlen(arr[j])) {
			shifts++;
			char * temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j = j - 1;
		}	
	}
	return shifts;
}


