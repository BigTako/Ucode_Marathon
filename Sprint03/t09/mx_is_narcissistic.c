#include <stdbool.h>
double mx_pow(double n, unsigned int pow);

bool mx_is_narcissistic(int num)
{
    int digits[20];
    int len = 0;
    int n_sum = 0;
    int num_temp = num;
    if (num < 0)
    	return 0;
    while (num_temp > 0)
    {
        digits[len] = num_temp % 10;
        num_temp /= 10;
        len++;
    }
    for (int i = 0; i < len; i++)
        n_sum += mx_pow(digits[i], len);
    if (n_sum == num)
        return 1;
    return 0;
}


