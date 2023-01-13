void mx_printstr(const char *s);
int mx_strlen(const char *s);
char *mx_strchr(const char *s, int c);

int main(int argc, char * argv[])
{
	argc = 0;
	char * p_path = mx_strchr(argv[0], '/');
	while(mx_strchr(p_path + 1, '/'))
		p_path = mx_strchr(p_path + 1, '/');
	mx_printstr(p_path + 1);
	mx_printstr("\n");
	return 0;
}


