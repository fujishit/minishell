#include "minishell.h"

//環境変数を持ってきて本来の関数がある場所を探して、必要な場所を関数に渡す。

void	output_cmd(t_cmd *cmd)
{
	size_t i;
	t_meta *meta_tmp;
	t_cmd *cmd_tmp;

	cmd_tmp = cmd;
	while (cmd_tmp != NULL)
	{
		printf("\x1b[34m");
		printf("command details\n");
		printf("command: ");
		fflush(stdout);
		printf("[%s]\n", cmd_tmp->argv[0]);
		printf("arguments:");
		i = 1;
		printf("[");
		fflush(stdout);
		while (i < cmd_tmp->argc)
		{
			printf("%s, ", cmd_tmp->argv[i]);
			fflush(stdout);
			i++;
		}
		if (1 < i)
			printf("\b\b");
		printf("]\n");
		meta_tmp = cmd_tmp->nextmeta;
		if (meta_tmp == NULL)
			break ;
		printf("\x1b[32m");
		if (meta_tmp->meta != NO_REDIRECT)
		{
			if (meta_tmp->meta == REDIRECT_IN)
				printf("INPUT_REDIRECT \"<\"\n");
			else if (meta_tmp->meta == HERE_DOCUMENT)
				printf("HERE_DOCUMENT \"<<\"\n");
			else if (meta_tmp->meta == REDIRECT_OUT)
				printf("REDIRECT_OUT \">\"\n");
			else if (meta_tmp->meta == ADD_REDIRECT_OUT)
				printf("APPEND_REDIRECT_OUT \">>\"");
		}
		cmd_tmp = meta_tmp->nextcmd;
	}
	printf("\x1b[39m");
	fflush(stdout);
}

void	output_list(t_list *lex)
{
	while (lex != NULL)
	{
		printf("%s\n", (char *)lex->content);
		lex = lex->next;
	}
}

int	launcher(t_cmd *cmd)
{
	if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(cmd->argv[0], "echo") == 0)
		echo(cmd->argc, cmd->argv);
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
			lexer(line, &lex_cmd);
			free(line);
			parser(lex_cmd, &cmd);
			output_cmd(cmd);
			launcher(cmd);
			free_list(lex_cmd);
			free_cmd(cmd);
			line = NULL;
			write(1, "\n", 1);
		}
	}
}
