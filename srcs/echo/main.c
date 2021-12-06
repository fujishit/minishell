#include "minishell.h"
#include "echo.h"

static t_option	init_option(void)
{
	t_option	opt;

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
	int			i;
	t_option	opt;

	i = 1;
	opt = init_option();
	while (check_option(&opt, argv[i]) == 1)
		i++;
	printf("%s", argv[i]);
	i++;
	while (i < argc)
	{
		printf(" ");
		printf("%s", argv[i]);
		i++;
	}
	if (opt.n != 1)
		printf("\n");
	return (0);
}
