#include <unistd.h>

void mx_printchar(char c)
{
	write(1, &c, 1);
}

void mx_printstr(const char *s)
{
	for (int i = 0; s[i] != '\0'; i++) mx_printchar(s[i]);
}


