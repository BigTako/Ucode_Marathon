#include "exterminate_agents.h"

void mx_exterminate_agents(t_agent ***agents)
{
	for (int i = 0; (*agents)[i]; i++)
	{
		free((*agents)[i]->name);
		free((*agents)[i]);
		(*agents)[i] = NULL;
	}
	**agents = 0;
}


