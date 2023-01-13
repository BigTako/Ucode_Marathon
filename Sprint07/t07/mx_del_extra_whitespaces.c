#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool mx_isspace(char c);
void mx_strdel(char **str);
char * mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strtrim(const char *str);

char *mx_del_extra_whitespaces(const char *str) {
	if (!str || str[0] == '\0') return NULL;
	char * trimmed = mx_strtrim(str);
	char * temp;
	char * result = NULL;
	int len = mx_strlen(trimmed);
	int beg = 0;
	for (int i = 0; i <= len; i++){
		if (mx_isspace(trimmed[i])) continue;
		beg = i;
		while (!mx_isspace(trimmed[i]) && i != len) i++;
		temp = result;
		result = mx_strnew(mx_strlen(temp) + i - beg + 1);
		mx_strncpy(result, temp, mx_strlen(temp));
		mx_strncpy(result + mx_strlen(temp), trimmed + beg, i - beg);
		if (trimmed[i + 1] != '\0')
			result[mx_strlen(result)] = ' ';
		mx_strdel(&temp);
	}
	mx_strdel(&trimmed);
	return result;
}

int main(void){
	//char s[] =  "";
	char * st = mx_del_extra_whitespaces(" My   ass   hurts   ");
	printf("%s\n", st);
	free(st);
	return 0;
}
