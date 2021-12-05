#include "minishell.h"

static void	free_argv(int argc, char **argv)
{
	size_t	i;

	i = 0;
	while (i < argc)
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*cmd_tmp;
	t_meta	*meta_tmp;

	cmd_tmp = cmd;
	while (cmd_tmp != NULL)
	{
		meta_tmp = cmd_tmp->nextmeta;
		free_argv(cmd_tmp->argc, cmd_tmp->argv);
		free(cmd_tmp);
		cmd_tmp = NULL;
		if (meta_tmp == NULL)
			break ;
		cmd_tmp = meta_tmp->nextcmd;
		free(meta_tmp);
		meta_tmp = NULL;
	}
}

//parseで使う都合で、contentをfreeしてはいけない。
//strdupでcontentをとってきたらいいというとこでもあるから、その辺は後々
void	free_list(t_list *lex)
{
	t_list	*tmp;

	while (lex != NULL)
	{
		tmp = lex;
		lex = lex->next;
		free(tmp);
	}
}
