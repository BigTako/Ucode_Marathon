#include "read_file.h"
int main(int argc, char * argv[])
{	
	if (argc != 2){
		char buf[256]; 
		while(read(0, buf, 1)){
		    write(1, buf, mx_strlen(buf));
		    //mx_printchar('\n');
		}
		return 0;
	}
	char c;
	int bytes;
	int fd_to_read = open(argv[1], O_RDONLY);
	if (fd_to_read == -1) {		
		mx_printerr("mx_cat: ");
		mx_printerr(argv[1]);
		mx_printerr(": No such file or directory\n");
		return 0;
	}else
		while ((bytes = read(fd_to_read, &c, sizeof(c))) > 0)
			write(1, &c, sizeof(c));
	close(fd_to_read);
	return 0;
}


