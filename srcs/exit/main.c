#include <minishell.h>

void ft_exit(t_cmd *cmd)
{
	free_cmd(cmd);
	exit(0);
}
