#include "minishell.h"

//free後にNULLしとくといいかも
void	free_cmd(t_cmd **cmd)
{
	size_t	i;
	size_t	n;

	i = 0;
	while (cmd[i] != NULL)
	{
		n = 0;
		while (cmd[i]->argv[n] != NULL)
		{
			free(cmd[i]->argv[n]);
			n++;
		}
		free(cmd[i]->argv);
		i++;
	}
	free(cmd);
}
