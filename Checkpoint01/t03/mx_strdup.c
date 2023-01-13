#include <stdlib.h>
#include <stdio.h>

char *mx_strnew(const int size)
{
	if (size < 0) return NULL;
	char * str = malloc((size + 1)*sizeof(char));
	for (int i = 0; i < size; i++) str[i] = '\0';
	return str;
}

char *mx_strcpy(char *dst, const char *src)
{
    int i = 0;
    for (; src[i] != '\0'; i++)
        dst[i] = src[i];
    dst[i + 1] = '\0';     
    return dst;
}

int mx_strlen(const char *s)
{
	if (!s) return 0;
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}


char *mx_strdup(const char *str)
{
	return mx_strcpy(mx_strnew(mx_strlen(str)), str);
}


