int mx_atoi(const char *str);
void mx_printint(int n);
void mx_printchar(char c);


int main(int argc, char * argv[])
{
	int sum = 0;
	if (argc < 2) return 0;
	for (int i = 1; i < argc; i++)
	{
		int cur = mx_atoi(argv[i]);
		if (cur) sum += cur;	
	}
	mx_printint(sum);
	mx_printchar('\n');
	return 0;
}


