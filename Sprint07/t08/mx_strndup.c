#include <stdlib.h>
#include <stdio.h>

char * mx_strnew(const int size);
char * mx_strncpy(char *dst, const char *src, int len);

char * mx_strndup( const char * s1, size_t n)
{
    return mx_strncpy(mx_strnew(n), s1, n);
}

/*int main()
{
    char s1 [] = "my ass hurts";
    printf("%s\n", mx_strndup(s1, 5));
    return 0;
}*/

