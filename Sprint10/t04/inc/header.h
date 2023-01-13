#ifndef FILE_TO_STR_H
#define FILE_TO_STR_H
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <unistd.h>
bool mx_isspace(char c);
void mx_printchar(char c);
void mx_printint(int n);
void mx_printerr(const char *s);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_file_to_str(const char *filename);
int mx_count_words(const char *str, char delimiter);
char * mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);
char ** mx_strsplit(char const *s, char c);
int mx_strcmp(const char *s1, const char *s2);
#endif


