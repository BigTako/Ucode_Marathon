int mx_strlen(const char *s)
{
	char c = s[0];
	int i = 0;
	while (c != '\0')
	{
		c = s[i];
		i++;
	}
	return (i - 1);
}


