#include "encryptor.h"

void mx_add_one(char * str, const char * pattern, int c, int * off)
{
	if (c == -1){
		*off = 1;
		return;
	} 
	else if (pattern[c] != '?') mx_add_one(str, pattern, c - 1, off);
	else
		if (str[c] == '9'){
			str[c] = '0';
			mx_add_one(str, pattern, c - 1, off);
		}else str[c]++;
}

char * mx_get_init_num(char * pattern) {
	char * copy = mx_strdup(pattern);
	if (mx_strcmp(pattern, "?") == 0) {
		copy[0] = '0';
	} else 
		for (int i = 0; pattern[i] != '\0'; i++)
			if (pattern[i] == '?') copy[i] = '0';
	return copy;
}


char * mx_reinit_str(char * str, char * pattern, int * ovf)
{
	*ovf = 0;
	mx_strdel(&str);
	return mx_get_init_num(pattern);
}

void mx_print_comb(char * n1, char * n2, char * res, char op){
	mx_printint(mx_atoi(n1));
	mx_printchar(' ');
	mx_printchar(op);
	mx_printchar(' ');
	mx_printint(mx_atoi(n2));
	mx_printchar(' ');
	mx_printchar('=');
	mx_printchar(' ');
	mx_printint(mx_atoi(res));	
	mx_printchar('\n');
}



