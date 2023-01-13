#include "encryptor.h"
char *mx_strtrim(const char *str, int obj, int * err)
{
	if (!str){
		 *err = 1;
		 return 0;
	}
	int beg = 0;
	int end = mx_strlen(str);
	for (; str[beg] != '\0'; beg++)
		if (mx_isspace(str[beg])) continue;
		else if (mx_isdigit(str[beg])) break;
		else if (str[beg] == '?') break;
		else if (mx_isoperation(str[beg])) break;
		else{
			 *err = 1;
			 return 0;
		}
	for (; end >= 0; end--)
		if (mx_isspace(str[end - 1])) continue;
		else if (str[end - 1] == '?') break;
		else if (mx_isdigit(str[end - 1]) && obj == OPERAND) break;
		else if (mx_isoperation(str[end - 1]) && obj == OPERATION) break;
		else{
			*err = 1;
			return 0;
		}
	if (end - beg != 1 && obj == OPERATION){
		 *err = 1;
		 return 0;
	}
	char *result = mx_strnew(end - beg);
	result = mx_strncpy(result, str + beg, end - beg);
	return result;
}


