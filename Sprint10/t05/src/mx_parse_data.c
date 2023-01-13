#include "header.h"

char ** get_names(char * text, int count){
	char ** names = malloc(count*sizeof(char *));
	text = mx_strstr(text, "name");
	int name_len = 0;
	char * name;
	int name_i = 0;
	while (text){
		for (;(text + 5)[name_len] != '\n'; name_len++);
		name = mx_strnew(name_len+1);
		name = mx_strncpy(name, (text + 6), name_len-1);
		names[name_i] = name;
		name_i++;
		text = mx_strstr(text + 1, "name");
	}
	return names;
}

int * get_powers(char * text, int count){
	int * powers = malloc(count*sizeof(int));
	text = mx_strstr(text, "power");
	int num_len = 0;
	char * num;
	for (int num_i = 0; text; num_i++){
		num_len = 0;
		for (;(text + 6)[num_len] != '\n'; num_len++);
		num = mx_strncpy(mx_strnew(num_len+1), text + 7, num_len-1);
		powers[num_i] = mx_atoi(num);
		text = mx_strstr(text + 1, "power");
		free(num);
	}
	return powers;
}

int * get_strength(char * text, int count){
	int * strengths = malloc(count*sizeof(int));
	text = mx_strstr(text, "strength");
	int num_len = 0;
	char * num;
	for (int num_i = 0; text; num_i++){
		num_len = 0;
		for (;(text + 9)[num_len] != '\n'; num_len++);
		num = mx_strncpy(mx_strnew(num_len+1), text + 10, num_len-1);
		strengths[num_i] = mx_atoi(num);
		text = mx_strstr(text + 1, "strength");
		free(num);
	}
	return strengths;
}
