#include "minishell.h"

//環境変数を持ってきて本来の関数がある場所を探して、必要な場所を関数に渡す。

void	output(t_list *lex)
{
	while (lex != NULL)
	{
		printf("%s\n", lex->content);
		lex = lex->next;
	}
}

void	free_list(t_list *lex)
{
	t_list *tmp;

	while (lex != NULL)
	{
		tmp = lex;
		lex = lex->next;
		free(tmp->content);
		free(tmp);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_list	*lex_cmd;
	t_cmd	*cmd;

	if (argc == 1)
	{
		while (1)
		{
			write(1, "MINISHELL $>", 12);
			line = command_input(envp);
			ms_lexer(line, &lex_cmd);
			free(line);
			output(lex_cmd);
			ms_parser(lex_cmd, &cmd);
			free_list(lex_cmd);
			line = NULL;
			write(1, "\n", 1);
		}
	}
}
