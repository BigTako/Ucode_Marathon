#include "header.h"

int mx_filelen(int file){
	char c;
	int bytes;
	int count = 0;
	while ((bytes = read(file, &c, sizeof(c))) > 0) count++;
	return count;
}


