#include "minishell.h"

//zshでは2つ引数を取る場合がある
//  cd old newでcurrent directoryからoldをnewに書き換えた値になる
//例えば、~/42tokyo/$ cd tokyo ecole --> cd ~/42ecole

//bashでは引数の数ではエラーが出ないっぽい？

static char	*get_homedir(char *envp[])
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "HOME=", 4) == 0)
		{
			return (envp[i] + 5);
		}
		i++;
	}
	return (NULL);
}

int	cd(int argc, char **argv, char *envp[])
{
	char	*path;

	if (argc == 1 || ft_strcmp(argv[1], "~") == 0)
		path = get_homedir(envp);
	else
		path = argv[1];
	if (chdir(path) != 0)
	{
		write(1, "minishell: cd: ", 15);
		write(1, argv[1], ft_strlen(argv[1]));
		write(1, ": No such file or directory\n", 29);
		return (1);
	}
	return (0);
}
