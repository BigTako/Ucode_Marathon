#include "path_finder.h"

char * delete_comas(char * str, char c, int len, int  * ERR){
	char * result = mx_strnew(len / 2 + 1);
	int j = 0;
	for (int i = 0; i < len; i++){
		if (str[i] == '#' || str[i] == '.') result[j++] = str[i];	
		else if (str[i] == c) continue;
		else{
			*ERR = 1;
			throw_error(MAP_ERR, 0); // forbiden chars in map
			mx_strdel(&result);
			return 0;
		}
	}
	return result;
}


