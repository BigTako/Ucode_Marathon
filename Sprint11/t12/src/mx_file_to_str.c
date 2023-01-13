#include "header.h"

char *mx_file_to_str(const char *filename)
{
	int file = open(filename, O_RDONLY);
	if (file == -1){
		mx_printerr("ERROR\n");
		exit(0);
	}
	char c;
	int bytes;
	int len = 0;
	char * a;
	while ((bytes = read(file, &c, sizeof(c))) > 0) len++;
	char buf[len];
	close(file);
	file = open(filename, O_RDONLY);
	read(file, buf, sizeof(buf));	
	close(file);
	a = mx_strdup(buf);
	a[len] = '\0';
	return a;
}


