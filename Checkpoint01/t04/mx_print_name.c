#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int mx_strlen(const char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}

void mx_printchar(char c)
{
	write(1, &c, 1);
}

void mx_printint(int n)
{
	int digits[20];
	int lenght = 0;
	if (n < 0)
	    mx_printchar('-');
	else if (n == 0) 
		mx_printchar('0');
	while (n != 0)
	{
		if (n % 10 < 0)
	 		    digits[lenght] = -(n % 10);
		else
		    	digits[lenght] = n % 10;
		lenght++;
		n /= 10;
    	}
    	for(int i = lenght - 1;i >= 0;i--)
        	mx_printchar(48 + digits[i]);
}

void mx_printstr(const char *s)
{
	write(1, s, mx_strlen(s));
}


int main( int argc, char *argv[] )
{
	mx_printstr(argv[0]);
	mx_printchar('\n');
	mx_printint(argc);
	mx_printchar('\n');
	return 0;
}




