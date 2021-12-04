#include "minishell.h"

int	pwd()
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	write(1, pwd, ft_strlen(pwd));
	write(1, "\n", 1);
	return (0);
}
