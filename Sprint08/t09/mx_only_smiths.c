#include "only_smiths.h"
t_agent **mx_only_smiths(t_agent **agents, int strength)
{
	if (!agents) return NULL;
	int cneed = 0;
	t_agent * t;
	for (int i = 0; agents[i]; i++)
		if (mx_strcmp(agents[i]->name, "Smith") == 0
		     		&& agents[i]->strength < strength) cneed++;	
	t_agent ** result = malloc((cneed + 1)*sizeof(t_agent *));
	cneed = 0;
	for (int i = 0; agents[i]; i++)
		if (mx_strcmp(agents[i]->name, "Smith") == 0
		     		&& agents[i]->strength < strength)
		{
			t = agents[i];
			result[cneed++] = mx_create_agent(t->name, t->power, t->strength);
		}	
	mx_exterminate_agents(&agents);
	result[cneed] = NULL;
	return result;
}


