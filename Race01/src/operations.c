#include "minilibmx.h"

int mx_add(int a, int b)
{
	return a + b;
}
int mx_sub(int a, int b)
{
	return a - b;
}
int mx_mul(int a, int b)
{
	return a * b;
}
int mx_div(int a, int b)
{
	return a / b;
}
int mx_mod(int a, int b)
{
	return a % b;
}

bool mx_isoperation(char c)
{
	return c == '+' || 
			c == '-' 
				|| c == '/' 
					|| c == '*';
}	

