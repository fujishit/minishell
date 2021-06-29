#include "minishell.h"

int	ms_issep(char c)
{
	if (c == '|')
		return (1);
	else if (c == '<')
		return (1);
	else if (c == '>')
		return (1);
	else if (c == ' ')
		return (1);
	else if (c == '\0')
		return (-1);
	return (0);
}
