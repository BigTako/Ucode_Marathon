#include "header.h"

char ** mx_strsplit(char const *s, char c)
{
	char** arr = malloc((mx_count_words(s, c) + 1) * sizeof(char*));
	int word_indx = 0;
	int len = 0;
	int beg = 0;
	for (; s[len] != '\0'; len++);
	for (int i = 0; i <= len; i++)
	{
		if (s[i] == c) continue;
		beg = i;
		while (s[i] != c && s[i] != '\0') i++;
		if (beg == i) break;
		arr[word_indx] = mx_strnew(i - beg);
		mx_strncpy(arr[word_indx++], s + beg, i - beg);
	}
	arr[word_indx] = 0;
	return arr;
}


