#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool mx_isspace(char c);
void mx_strdel(char **str);
char * mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
int mx_strlen(const char *s);

char *mx_strtrim(const char *str)
{
	if (!str) return NULL;
	int beg = 0;
	int end = mx_strlen(str);
	for (; mx_isspace(str[beg]); beg++);
	for (; mx_isspace(str[end - 1]); end--);
	char *result = mx_strnew(end - beg + 1);
	result = mx_strncpy(result, str + beg, end - beg);
	return result;
}



