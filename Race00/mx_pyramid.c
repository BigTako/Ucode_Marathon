void mx_printchar(char c);

void mx_print_string(int n, char right, char left, char fill)
{
	if (right) mx_printchar(right);
	if (fill) for (int i = 0; i < n; i++) mx_printchar(fill);
	if (left) mx_printchar(left);
}

void mx_pyramid(int n) {
	if (n < 2
		|| n % 2 != 0) return;
	for (int i = 0; i < n - 1; i++)
	{
		mx_print_string(n - i - 1, 0, '/', ' '); 
		if ( i > 0 ) mx_print_string(2 * i - 1, 0, '\\', ' ');
		if ( i < n / 2 ) mx_print_string(i, 0, '\\', ' '); 
		else mx_print_string(n - i - 1, 0, '|', ' '); 
		mx_printchar('\n');
	}
	mx_print_string(2 * n - 3, '/', '\\', '_');
	mx_print_string(2, '|', '\n', 0);
}


