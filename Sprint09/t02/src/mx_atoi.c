#include "functions.h"

int mx_atoi(const char* str)
{
    int num = 0;
    int i = 0;
    int ten_pow;
    int num_len = 0;
    if (!str) return num;
    for (int c = 0; !mx_isdigit(str[c]); c++)
    	if (mx_isspace(str[c])) i = c;
    	else if ( str[c] == '-' || str[c] == '+')
    		if ( mx_isdigit(str[c + 1])) i = c + 1;
    		else return 0;
    	else return 0;
    for (; mx_isdigit(str[num_len + i]); num_len++);
    if (!mx_isdigit(str[i + num_len + 1]) 
    	&& str[i + num_len] != '\0') return 0; 
    for (int q = i; q < i + num_len; q++) {
        ten_pow = 1;
	for (int j = 0; j < num_len + i - q - 1; j++) ten_pow *= 10;
	num += (str[q] - 48) * ten_pow; 
    }
    if (str[i-1] == '-') num = -num;
    return num;
}

