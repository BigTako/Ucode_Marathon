#include "get_address.h"

char *mx_get_address(void *p)
{
	if (!p) return "(nil)";
	unsigned long a = (unsigned long)p;
    	char * str_a = mx_nbr_to_hex(a);
    	int a_len = mx_strlen(str_a);
    	char * ha = mx_strnew(a_len + 2);
    	ha[0] = '0';
    	ha[1] = 'x';
    	mx_strcpy(ha + 2, str_a);
    	free(str_a);
    	return ha;	
}


