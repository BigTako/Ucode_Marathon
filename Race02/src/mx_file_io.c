#include "path_finder.h"

int open_file(char * filename)
{
	int file = open(filename, O_WRONLY | O_TRUNC);
	if (file == -1) throw_error(ERROR, 1);
	return file;	
}

void clear_file(char * filename){
	int file = open_file(filename);
	int len = mx_filelen(file);
	for (int i = 0; i < len; i++) write(file, " ", 1);
}

void write_to_file(char * str, char * filename, bool crear){
	
	int file = open_file(filename);
	if (crear) clear_file(filename); 
	write(file, str, mx_strlen(str));
}


