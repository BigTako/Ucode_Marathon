#include <unistd.h>

void mx_printchar(char c)
{
	write(1, &c, 1);
}

void mx_only_printable()
{
	for (int i = 126; i > 31; i--)
		mx_printchar(i);
	mx_printchar('\n');
}


