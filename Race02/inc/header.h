#ifndef FILE_TO_STR_H
#define FILE_TO_STR_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>

int mx_get_nlc(char * text);

int throw_error(int code, int ex);

void mx_validate_argc(int argc, char * argv[]);

bool mx_isspace(char c);

bool mx_isdigit(int c);

void mx_printerr(const char *s);

char *mx_strnew(const int size);

char *mx_strcpy(char *dst, const char *src);

char *mx_strdup(const char *str);

char *mx_file_to_str(const char *filename);

int mx_count_words(const char *str, char delimiter);

char * mx_strncpy(char *dst, const char *src, int len);

void mx_strdel(char **str);

int mx_strlen(const char *s);

int mx_atoi(const char* str);

void mx_strdel(char **str);

char ** mx_strsplit(char const *s, char c);

int mx_filelen(int file);

int validate_point(int * points, char ** map, int rows, int p_e);

char * delete_comas(char * str, char c, int len, int  * ERR);

void mx_printchar(char c);

void mx_printint(int n);

#endif


