#include "header.h"

t_agent *mx_create_agent(char *name, int power, int strength)
{
	if (!name) return NULL;
	t_agent * t = malloc(sizeof(t_agent));
	t->name = mx_strdup(name);
	t->strength = strength;
	t->power = power;
	return t;	
}

void mx_exterminate_agents(t_agent ***agents)
{
	for (int i = 0; (*agents)[i]; i++)
	{
		free((*agents)[i]->name);
		free((*agents)[i]);
		(*agents)[i] = NULL;
	}
	free(*agents);
}

t_agent ** mx_take_data(char * text, int n_c, int p_c, int s_c){
	char ** names = get_names(text, n_c);
	int * powers = get_powers(text, p_c);
	int * s = get_strength(text, s_c);
	t_agent ** agents = malloc(n_c*sizeof(t_agent *));
	for (int i = 0; i < n_c; i++){
		agents[i] = mx_create_agent(names[i], powers[i], s[i]);
		free(names[i]);
	}
	free(names[n_c]);
	free(names);
	free(powers);
	free(s);		
	return agents;	
}
