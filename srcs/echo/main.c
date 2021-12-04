#include "minishell.h"

int	echo(int argc, char **argv)
{
	int	i;

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
	return (0);
}
