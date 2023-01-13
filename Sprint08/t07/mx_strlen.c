#include "create_new_agents.h"
int mx_strlen(const char *s)
{
	if (!s) return 0;
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}


