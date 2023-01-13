int mx_strlen(const char *s);
char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub)
{
	int count = 0;
  	int l_s = mx_strlen(sub);
  	str = mx_strstr(str, sub);
  	while (str)
  	{
   	 	count++;
      	str = mx_strstr(str + l_s, sub);
	}
	return count;
}


