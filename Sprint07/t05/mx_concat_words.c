#include <stdlib.h>
#include <stdio.h>

char *mx_strjoin(char const *s1, char const *s2);
char *mx_strcat(char *s1, const char *s2);
void mx_strdel(char **str);

char *mx_concat_words(char**words)
{	
	if (!words 
		|| !words[0]) return NULL;	
	char * temp;
	char * arr = mx_strjoin(NULL, words[0]);
	for (int i = 1; words[i]; i++)
	{
		temp = arr;
		arr = mx_strjoin(mx_strcat(arr, " "), words[i]);	
		mx_strdel(&temp);
	}
	return arr;
}



