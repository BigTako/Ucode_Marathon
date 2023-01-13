#include <stdbool.h>

int mx_toupper(int c)
{
    if (c > 96 
    	&& c < 123) return c - 32; // if uppercase
    return c;
}


