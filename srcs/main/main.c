#include "minishell.h"
# define MINISHELL "MINISHELL $> "

void	sig_int_input()
{
	ft_putstr_fd("\b\b  \b\n", 2);
	ft_putstr_fd(MINISHELL, 2);
}

void	sig_quit_input()
{
	ft_putstr_fd("\b\b  \b\b", 2);
}

char	*command_input(char *envp[])
{
	char	*line;
	int		ret;

	ret = 0;
	line = NULL;
	if (signal(SIGINT, sig_int_input) == SIG_ERR)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit (1);
	}
	if (signal(SIGQUIT, sig_quit_input) == SIG_ERR)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit (1);
	}
	if (get_next_line(0, &line) == 0)
	{
		ft_putstr_fd("exit\n", 1);
		exit (ret);
	}
	return (line);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;

	if (argc == 1)
	{
		while (1)
		{
			ft_putstr_fd(MINISHELL, 1);
			line = command_input(envp);
			ft_putstr_fd(line, 1);
			ft_putstr_fd("\n", 1);
			free(line);
		}
	}
}
