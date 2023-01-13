#include "create_new_agents.h"

t_agent **mx_create_new_agents(char **name, int *power, int * strength, int count)
{
	if (!name || 
		!power || 
			!strength) return NULL;
	if (!name[0]) return NULL;
	t_agent ** agents = malloc((count + 1) * sizeof(t_agent *));
	for (int i = 0; i < count; i++)
		agents[i] = mx_create_agent(name[i], power[i], strength[i]);	
	agents[count] = (t_agent *)NULL;
	return agents;
}


