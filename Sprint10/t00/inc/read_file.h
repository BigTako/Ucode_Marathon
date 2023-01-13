#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int mx_strlen(const char *s);
void mx_printerr(const char *s);
int mx_filelen(int file);
#endif

