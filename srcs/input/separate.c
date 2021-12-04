#include "minishell.h"

/*"| <>"で1,null文字が-1,それ以外が0で返る関数*/
int	issep(char c)
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
