#include <unistd.h>

void mx_printchar(char c);

void mx_isos_triangle(unsigned int lenght, char c)
{
	for (unsigned int i = 0 ; i < lenght; i++)
	{
		for (unsigned int j = 0; j <= i; j++)
			mx_printchar(c);
		mx_printchar('\n');
	}
}


