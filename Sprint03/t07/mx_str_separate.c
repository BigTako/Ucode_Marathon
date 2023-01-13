#include <unistd.h>
void mx_printchar(char c);

void mx_str_separate(const char* str, char delim)
{
    for (int f_p = 0; str[f_p] != '\0'; f_p++)
        if (str[f_p] == delim 
        	&& str[f_p + 1] != delim)
            mx_printchar('\n');
        else if (str[f_p] != delim) 
            mx_printchar(str[f_p]);
    mx_printchar('\n');
}


