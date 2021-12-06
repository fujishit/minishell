#include "minishell.h"

//環境変数を持ってきて本来の関数がある場所を探して、必要な場所を関数に渡す。

void	output_cmd(t_cmd *cmd)
{
	size_t i = 0;
	t_meta *meta_tmp = NULL;
	t_cmd *cmd_tmp = NULL;

	if (cmd == NULL)
		return ;
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

static int	launcher(t_cmd *cmd, char *envp[])
{
	if (cmd == NULL)
		return (1);
	else if (ft_strcmp(cmd->argv[0], "echo") == 0)
		return (echo(cmd->argc, cmd->argv));
	else if (ft_strcmp(cmd->argv[0], "cd") == 0)
		return (cd(cmd->argc, cmd->argv, envp));
	else if (ft_strcmp(cmd->argv[0], "pwd") == 0)
		return (pwd());
	// else if (ft_strcmp(cmd->argv[0], "export") == 0)
		// return (export());
	// else if (ft_strcmp(cmd->argv[0], "unset") == 0)
		// return (unset());
	else if (ft_strcmp(cmd->argv[0], "env") == 0)
		return (env(envp));
	else if (ft_strcmp(cmd->argv[0], "exit") == 0)
		ft_exit(cmd);
}

static int	terminal_out()
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	write(1, "minishell: ", 11);
	write(1, pwd, ft_strlen(pwd));
	write(1, " $> ", 4);
	return (0);
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
			line = NULL;
			lex_cmd = NULL;
			cmd = NULL;
			// write(1, "MINISHELL $>", 12);
			terminal_out();
			line = command_input(envp);
			lexer(line, &lex_cmd); //分割
			free(line);
			// output_list(lex_cmd);
			parser(lex_cmd, &cmd); //パース
			free_list(lex_cmd);
			output_cmd(cmd); //パース結果を出力
			launcher(cmd, envp); //実行
			free_cmd(cmd);
		}
	}
}
