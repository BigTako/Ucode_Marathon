int mx_factorial_iter(int n)
{
	int fac = 1;
	if (n < 0 
		|| n > 12) return 0;
	else if (n == 0) return 1;
	for (int i = 1; i <= n; i++)
		if (fac*i < 0) return 0;
		else fac *= i;
	return fac;
}


