int mx_sum_digits(int num)
{
    int sum = 0;
    while (num != 0)
    {
    	if (n % 10 < 0) sum += -(n % 10);
	    else sum += n % 10; 
        num /= 10;
    }
    return sum;
}


