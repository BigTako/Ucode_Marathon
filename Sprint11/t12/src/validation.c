#include "header.h"

bool search_wrong_input(char * str){
	for (int i = 0; str[i] != '\0'; i++)
		if (!mx_isdigit(str[i])) return 1;
	return 0;	
}

void throw_error(){
	mx_printerr("ERROR\n");
	exit(0);
}

void mx_validate_argc(int argc, char * argv[]){
	if (argc < 3){
		mx_printerr("usage: ");
		mx_printerr(argv[0]);
		mx_printerr(" [file] [command] [args]\n");
		exit(0);
	}else{
		if (mx_strcmp(argv[2], "add") == 0){
			if (argc != 5) throw_error(); 
		}else if (mx_strcmp(argv[2], "remove") == 0){
			if (argc != 4 || search_wrong_input(argv[3])) 
				throw_error();
		}else if (mx_strcmp(argv[2], "sort") == 0){
			if (argc != 4) throw_error();
		}else if (mx_strcmp(argv[2], "print") == 0){
			if (argc != 3) throw_error();
		}else{ 
			throw_error();
		}
	}
}

int mx_get_nlc(char * text){
	int c = 0;
	for (int i = 0; text[i] != '\0'; i++)
		if (text[i] == '\n') c++;
	return c;
}


