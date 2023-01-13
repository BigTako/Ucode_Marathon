#ifndef MINILIBMX_H
#define MINILIBMX_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void mx_printchar(char c);
void mx_printint(int n);
bool mx_isspace(char c);
bool mx_isdigit(int c);
bool mx_isoperation(char c);
void mx_strdel(char **str);
char * mx_strncpy(char *dst, const char *src, int len);
char *mx_strnew(const int size);
int mx_strlen(const char *s);
char *mx_strcpy(char *dst, const char *src);
char *mx_strtrim(const char *str, int obj, int * err);
void mx_printerr(const char *s);
char *mx_strdup(const char *str);
int mx_strcmp(const char *s1, const char *s2);
int mx_atoi(const char* str);

void mx_out_err(int code, char * op, int object);
char * mx_valid_obj(char * op, int object);
void mx_add_one(char * str, const char * pattern, int c, int * off);
char * mx_get_init_num(char * pattern);
int mx_cc(char * str, char c);
char * mx_reinit_str(char * str, char * pattern, int * ovf);
void mx_print_comb(char * n1, char * n2, char * res, char op);

int mx_add (int a, int b);
int mx_sub (int a, int b);
int mx_mul (int a, int b);
int mx_div (int a, int b);
#endif

