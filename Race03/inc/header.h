#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <stdbool.h>
#include <time.h>


int mx_strlen(const char *s);
void greeting(WINDOW * win, int w, int h);
void mx_validate_argc(int argc);
#endif


