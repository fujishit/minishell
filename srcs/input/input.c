#include "minishell.h"

static void	sig_int_input(int sig)
{
	(void)sig;
	ft_putstr_fd("\b\b  \b\n", 2);
	ft_putstr_fd(MINISHELL, 2);
}

static void	sig_quit_input(int sig)
{
	(void)sig;
	ft_putstr_fd("\b\b  \b\b", 2);
}

static void	signals(void)
{
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
}

char	*command_input(char *envp[])
{
	char	*line;
	char	*trim_line;
	int		ret;

	ret = 0;
	line = NULL;
	trim_line = NULL;
	signals();
	if (get_next_line(0, &line) == 0)
	{
		free(line);
		ft_putstr_fd("exit\n", 1);
		exit (ret);
	}
	trim_line = ft_strtrim(line, " \t");
	free(line);
	line = NULL;
	return (trim_line);
}
