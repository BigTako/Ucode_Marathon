#include "only_smiths.h"
t_agent *mx_create_agent(char *name, int power, int strength)
{
	if (!name) return NULL;
	t_agent * t = malloc(sizeof(t_agent));
	t->name = mx_strdup(name);
	t->strength = strength;
	t->power = power;
	return t;	
}


