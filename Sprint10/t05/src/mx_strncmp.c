int mx_strncmp(const char *s1, const char *s2, int n)
{ 
	int i = 0;
	if (!s1 && !s2)
	    return 0;
	while (i != n-1)
	{
		if (s1[i] != s2[i])
			return s1[i] - s2[i];
		i++;
	}
	return s1[i] - s2[i];
}


