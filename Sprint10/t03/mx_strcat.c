#include "file_to_str.h"
char *mx_strcat(char *s1, const char *s2)
{
    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);
    for (int i = 0; i <= len2; i++) s1[len1 + i] = s2[i];
    return s1;
}

