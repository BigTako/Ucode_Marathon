#ifndef MINILIBMX_H
#define MINILIBMX_H
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
void mx_printchar(char c);
void mx_printint(int n);
bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char* str, int * err);
int mx_strlen(const char *s);
void mx_printerr(const char *s);
#endif


