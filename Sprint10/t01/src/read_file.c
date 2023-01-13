#include "read_file.h"

int main(int argc, char * argv[])
{
	if (argc != 3){
		mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
		return 0;
	}
	char c;
	int bytes;
	int fd_to_read = open(argv[1], O_RDONLY);
	int fd_to_write = open(argv[2], O_WRONLY);
	if (fd_to_read == -1) {
		mx_printerr("mx_cp: ");
		mx_printerr(argv[1]);
		mx_printerr(": No such file or directory\n");
	}else if (fd_to_write == -1){
		fd_to_write = open(argv[2], O_WRONLY | O_CREAT);
		while ((bytes = read(fd_to_read, &c, sizeof(c))) > 0)
			write(fd_to_write, &c, sizeof(c));
	}
	close(fd_to_read);
	close(fd_to_write);
	return 0;
}


