#include "read_file.h"
int main(int argc, char * argv[])
{
	if (argc != 2){
		mx_printerr("usage: ./read_file [file_path]\n");
		return 0;
	}
	int file = open(argv[1], O_RDONLY);
	int len = 0;
	if (file == -1) {
		mx_printerr("error\n");
	}
	else{
		len = mx_filelen(file);
		char buf[len + 1];
		file = open(argv[1], O_RDONLY);	
		read(file, buf, sizeof(buf));
		buf[len] = '\0';
		write(1, buf, sizeof(buf));
		close(file);
	}
	return 0;
}


