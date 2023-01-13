#include "header.h"

void mx_printinfo(int nlc, int wc, int bytes, char * fname){
	mx_printchar('\t');
	mx_printint(nlc);
	mx_printchar('\t');
	mx_printint(wc);
	mx_printchar('\t');
	mx_printint(bytes);
	if (fname) {
		mx_printchar('\t');
		write(1, fname, mx_strlen(fname));
	}
	mx_printchar('\n');
}

int mx_get_nlc(char * text){
	int c = 0;
	for (int i = 0; text[i] != '\0'; i++)
		if (text[i] == '\n') c++;
	return c;
}

int mx_count_words_nl(char * text){
	char ** splitted = mx_strsplit(text, '\n');
	int words = 0;
	for (int i = 0; splitted[i]; i++){
		words += mx_count_words(splitted[i], ' ');
		free(splitted[i]);
		splitted[i] = NULL;
	}
	free(splitted);
	splitted = NULL;
	return words;
}


int main(int argc, char * argv[]){
	if (argc == 1 || argv[1][0] == '-'){
		int line = 0;
		int words = 0;
		int byte = 0;
		int state = 1;
		char c;
		while(read(0, &c, 1)){
		    byte++;
		    if (c == '\n') line++;
		    if (mx_isspace(c)) state = 1;
		    else if (state){
		  	state = 0;
		        words++;
		    }
		}
		mx_printinfo(line, words, byte, 0);
	}else{
		char * content;
		int nlc_total = 0;
		int wc_total = 0;
		int bytes_total = 0;
		for (int i = 1; i < argc; i++) {
			content = 0;
			content = mx_file_to_str(argv[i]);
			if (!content){
				free(content);	
				break;
			}
			nlc_total += mx_get_nlc(content);
			wc_total += mx_count_words_nl(content);
			bytes_total += mx_strlen(content);
			mx_printinfo(mx_get_nlc(content), mx_count_words_nl(content), mx_strlen(content), argv[i]);
			free(content);
		}
		if (argc > 2) 
			mx_printinfo(nlc_total, wc_total, bytes_total, "total"); 
	}
	return 0;
}


