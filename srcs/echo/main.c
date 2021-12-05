#include "minishell.h"
#include "echo.h"

static t_option	init_option()
{
	t_option opt;

	opt.n = 0;
}

static int	check_option(t_option *opt, char *argv)
{
	if (argv == NULL)
		return (0);
	else if (strcmp(argv, "-n") == 0)
	{
		opt->n = 1;
		return (1);
	}
	else
		return (0);
}

int	echo(int argc, char **argv)
{
	int	i;
	t_option opt;

	i = 1;
	opt = init_option();
	while (check_option(&opt, argv[i]) == 1)
		i++;
	write(1, argv[i], ft_strlen(argv[i]));
	i++;
	while (i < argc)
	{
		write(1, " ", 1);
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
	}
	if (opt.n != 1)
		write(1, "\n", 1);
	return (0);
}
