void mx_printstr(const char *s);
int mx_strcmp(const char *s1, const char *s2);

int main(int argc , char * argv[])
{
	if (argc < 1) return 0;
	for (int i = 1; i < argc - 1; i++)
		for (int j = 1; j < argc - i; j++)
		    if (mx_strcmp(argv[j], argv[j + 1]) > 0)
		    {
		    	char * temp = argv[j];
		    	argv[j] = argv[j+1];
		    	argv[j+1] = temp;
		    }  
	for (int i = 1; i < argc; i++){
		mx_printstr(argv[i]);
		mx_printstr("\n");
	}
	return 0;
}


