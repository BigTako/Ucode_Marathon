#include <unistd.h>

void mx_printchar(char c);

void mx_print_alphabet(void)
{
	for (int i = 65; i < 91; i++)
	{
		if ( i % 2 == 0) mx_printchar((char)(i+32));
		else mx_printchar((char)i); 
	}
	mx_printchar('\n');
}


