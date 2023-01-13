#include "header.h"

int mx_filelen(int file){
	char c;
	int bytes;
	int count = 0;
	while ((bytes = read(file, &c, sizeof(c))) > 0) count++;
	return count;
}


char *mx_file_to_str(const char *filename)
{
	int file = open(filename, O_RDONLY);
	if (file == -1){
		mx_printerr("mx_wc: ");
		mx_printerr(filename);
		mx_printerr(": open: No such file or directory\n");
		return 0;
	}
	else if (mx_filelen(file) == 0){
		mx_printerr("mx_wc: ");
		mx_printerr(filename);
		mx_printerr(": read: Is a directory\n");
		return 0;
	}
	close(file);
	file = open(filename, O_RDONLY);
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


