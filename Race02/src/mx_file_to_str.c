#include "path_finder.h"

char *mx_file_to_str(const char *filename)
{
	int file = open(filename, O_RDONLY);
	if (file == -1) throw_error(MAP_NOT_EXISTS_ERR, 1); // no file
	int len = mx_filelen(file);
	char * a;
	if (!len) throw_error(MAP_NOT_EXISTS_ERR, 1); // empty file
	char buf[len];
	close(file);
	file = open(filename, O_RDONLY);
	read(file, buf, sizeof(buf));	
	close(file);
	a = mx_strdup(buf);
	return a;
}


