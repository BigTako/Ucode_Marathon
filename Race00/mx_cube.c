void mx_printchar(char c);

void mx_print_string(int n, char border, char fill, char last)
{
	if (border)
	{
		mx_printchar(border);
		for (int i = 0; i < n; i++)
			mx_printchar(fill);
		mx_printchar(border);
	} else
		for (int i = 0; i < n; i++)  mx_printchar(fill);
	if (last) mx_printchar(last);
}

void mx_cube(int n)
{
	int j = 0;
	if (n < 2) return;
	mx_print_string(n/2 + 1, 0, ' ', 0);
	mx_print_string(2 * n, '+', '-', '\n');
	for (int i = 0; i < n / 2; i++){
		mx_print_string( n / 2 - i , 0, ' ', 0);
		mx_print_string( 2 * n, '/', ' ', 0);
		mx_print_string(i, 0, ' ', '|');
		mx_printchar('\n');		
	}
	mx_print_string(2 * n, '+', '-', 0);
	mx_print_string(n / 2, 0, ' ', '|');
	mx_printchar('\n');
	for (int i = 0; i < n; i++) {
		mx_print_string(2 * n, '|', ' ', 0);
		if (i == n - n / 2 - 1) mx_print_string( n / 2 , 0, ' ', '+');
		else if ( i < n - n / 2 - 1) mx_print_string(n / 2 , 0, ' ', '|');
		else mx_print_string(n / 2 - ++j , 0, ' ', '/');
		mx_printchar('\n');
	}
	mx_print_string(2 * n, '+', '-', '\n');
}


