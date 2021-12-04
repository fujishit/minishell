#include "minishell.h"

int	echo(char **argv)
{
	int	i;
	int	argc;

	argc = 0;
	while (argv[i] != NULL)
		argc++;
	if (argc != 1)
	{
		i = 1;
		write(1, argv[i], ft_strlen(argv[i]));
		i++;
		while (i < argc)
		{
			write(1, " ", 1);
			write(1, argv[i], ft_strlen(argv[i]));
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
