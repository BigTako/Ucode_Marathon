#ifndef FILE_TO_STR_H
#define FILE_TO_STR_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct s_agent{ 
	char *name;
	int power;
	int strength;
}t_agent;

bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printerr(const char *s);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);
char *mx_file_to_str(const char *filename);
int mx_count_words(const char *str, char delimiter);
char * mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);
char *mx_strstr(const char *s1, const char *s2);
int mx_strlen(const char *s);
int mx_strncmp(const char *s1, const char *s2, int n);
int mx_count_substr(const char *str, const char *sub);
int mx_atoi(const char* str);
int mx_strcmp(const char *s1, const char *s2);

char ** get_names(char * text, int count);
int * get_powers(char * text, int count);
int * get_strength(char * text, int count);
void swap_agents(t_agent * a, t_agent * b);
void mx_sort(t_agent ** arr, int size, bool(*f)(t_agent *, t_agent *));
t_agent *mx_create_agent(char *name, int power, int strength);
void mx_exterminate_agents(t_agent ***agents);
t_agent ** mx_take_data(char * text, int n_c, int p_c, int s_c);

bool ascending_p(t_agent * a, t_agent * b);
bool ascending_s(t_agent * a, t_agent * b);
bool ascending_n(t_agent * a, t_agent * b);
#endif


