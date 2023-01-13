int mx_popular_int(const int *arr, int size)
{
    int freqs[size];
    int cur_frq;
    int result_indx = 0;
    for (int i = 0; i < size; i++)
    {
            cur_frq = 1;
            for (int j = i; j < size; j++)
                if (arr[j] == arr[i])
                    cur_frq++;
            freqs[i] = cur_frq;
    }
    for (int i = 0; i < size; i++)
    {
        if (freqs[result_indx] < freqs[i])
            result_indx = i;
    }
    return arr[result_indx];
}


