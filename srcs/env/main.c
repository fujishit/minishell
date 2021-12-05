#include "minishell.h"

int	env(char *envp[])
{
	size_t	i;

	i = 0;
	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}
