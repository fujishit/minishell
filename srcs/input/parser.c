#include "minishell.h"
#include <stdio.h>
/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
*/
//リストの最後にたどり着くか、meta文字を見つけるまで回して数を数える関数
int	parse_argc(t_list *lex)
{
	size_t	i;

	i = 0;
	while (lex != NULL && ms_issep((char)((char *)lex->content)[0]) == 0)
	{
		lex = lex->next;
		i++;
	}
	return (i);
}

t_list	*parse_argv(t_cmd **new, t_list *lex)
{
	size_t	i;
	size_t	argc;

	if (lex == NULL)
		return (NULL);
	*new = (t_cmd *)malloc((size_t) sizeof(t_cmd) * 1);
	if (*new == NULL)
		return (NULL);
	(*new)->nextmeta = NULL;
	(*new)->argc = parse_argc(lex);
	(*new)->argv = malloc((size_t) sizeof(char *) * ((*new)->argc + 1));
	if ((*new)->argv == NULL)
		return (NULL);
	i = 0;
	while (i < (*new)->argc)
	{
		(*new)->argv[i] = (char *)lex->content;
		lex = lex->next;
		i++;
	}
	(*new)->argv[i] = NULL;
	return (lex);
}

t_list	*parse_meta(t_meta **new, t_list *lex)
{
	if (lex == NULL || lex->content == NULL)
		return (NULL);
	*new = (t_meta *)malloc((size_t) sizeof(t_meta) * 1);
	if (*new == NULL)
		return (NULL);
	(*new)->nextcmd = NULL;
	if (ft_strcmp((char *)lex->content, "<") == 0)
		(*new)->meta = REDIRECT_IN;
	else if (ft_strcmp ((char *)lex->content, "<<") == 0)
		(*new)->meta = HERE_DOCUMENT;
	else if (ft_strcmp ((char *)lex->content, ">") == 0)
		(*new)->meta = REDIRECT_OUT;
	else if (ft_strcmp ((char *)lex->content, ">>") == 0)
		(*new)->meta = ADD_REDIRECT_OUT;
	else if (ft_strcmp((char *)lex->content, "|") == 0)
		(*new)->meta = PIPE;
	else
		(*new)->meta = NO_REDIRECT;
	return (lex->next);
}

//t_cmd型に情報を格納する関数
int	ms_parser(t_list *lex, t_cmd **cmd)
{
	t_cmd	*newcmd;
	t_meta	*newmeta;

	lex = lex->next;
	lex = parse_argv(&newcmd, lex);
	*cmd = newcmd;
	while (lex != NULL)
	{
		lex = parse_meta(&newmeta, lex);
		newcmd->nextmeta = newmeta;
		newcmd = NULL;
		if (lex == NULL)
			break ;
		lex = parse_argv(&newcmd, lex);
		newmeta->nextcmd = newcmd;
		newmeta = NULL;
	}
	return (0);
}
