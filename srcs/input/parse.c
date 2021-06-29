#include "minishell.h"
#include <stdio.h>
/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
*/

int	ms_parser(t_list *lex, t_cmd **cmd)
{
	t_cmd	*new;


	while (lex != NULL)
	{
		lex = lex->next;
	}
	return (cmd);
}
