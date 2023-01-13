#include <stdio.h>
#include <stdlib.h>

void mx_swap_char(char *s1, char *s2)
{
    char s1_temp = *s1;
    *s1 = *s2;
    *s2 = s1_temp;
}

void mx_str_reverse(char *s, int len)
{
    int r = 0;
    int l = len - 1;
    for (; r < l; ) mx_swap_char(&s[r++], &s[l--]);
}

char *mx_strnew(const int size)
{
	if (size < 0) return NULL;
	char * str = malloc((size + 1)*sizeof(char));
	for (int i = 0; i < size; i++) str[i] = '\0';
	return str;
}

char *mx_nbr_to_hex(unsigned long nbr)
{
	int count = 0;
	unsigned long temp = nbr;
	for (; temp != 0; count++) temp /= 10;
	char * str_num = mx_strnew(count + 1);
	int i = 0;
	while (nbr != 0) {
        	temp = nbr % 16;
	 	if (temp < 10) str_num[i++] = temp + 48;
		else str_num[i++] = temp + 87;
		nbr = nbr / 16;	
        }
	mx_str_reverse(str_num, i);
	return str_num;
}



