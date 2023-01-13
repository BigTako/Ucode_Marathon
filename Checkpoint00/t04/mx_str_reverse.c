int mx_strlen(const char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}

void mx_swap_char(char* s1, char* s2)
{
    char s1_temp = *s1;
    *s1 = *s2;
    *s2 = s1_temp;
}

void mx_str_reverse(char * s)
{
	int r = 0;
	int l = mx_strlen(s)-1;
	for (; r < l; )
	{
		mx_swap_char(&s[r], &s[l]);
		r++;
		l--;		
	}
}


