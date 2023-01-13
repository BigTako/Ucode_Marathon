#include "header.h"


void mx_validate_argc(int argc){
	if (argc != 1){
		write(2, "usage: ./matrix_rain\n", mx_strlen("usage: ./matrix_rain\n"));
		exit(0);
	}
}


