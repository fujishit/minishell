#include "minishell.h"

static char	*env_get(char *argv, char *envp[])
{
	size_t	i;
	size_t	len;

	len = 0;
	while (argv[len] != '\0' && argv[len] != '$')
		len++;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(argv, envp[i], len) == 0)
			return (envp[i]);
		i++;
	}
	return ("\0");
}

static char	*env_expand(char *argv, char *env, size_t env_len)
{
	char	*ret;
	size_t	i;
	size_t	n;
	size_t	j;
	size_t	k;
	static int d = 1;

	i = 0;
	while (argv[i] != '$')
		i++;
	n = 1;
	while (argv[i + n] != '\0' && argv[i + n] != '$')
		n++;
	k = 0;
	while (argv[i + n + k] != '\0')
		k++;
	j = 0;
	while (env[j] != '=' && env[j] != '\0')
		j++;
	ret = (char *)malloc(sizeof(char) * (i + (env_len - j) + k + 1));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, argv, i + 1);
	ft_strlcpy(ret + i, env + (j + 1), env_len + j + 1);
	ft_strlcpy(ret + ft_strlen(ret), argv + i + n, k + 1);
	return (ret);
}

static char	*exp_env(char *argv, char *envp[])
{
	char	*ret;
	char	*env_tmp;
	size_t	i;

	i = 0;
	ret = argv;
	while (argv[i] != '\0')
	{
		if (argv[i] == '$')
		{
			env_tmp = env_get(argv + (i + 1), envp);
			ret = env_expand(argv, env_tmp, ft_strlen(env_tmp));
			free(argv);
			argv = ret;
			i = 0;
		}
		i++;
	}
	return (argv);
}

//$****等を展開,""と''の除去
int	ms_expansion(char **argv, char *envp[])
{
	t_list	*list;
	size_t	i;

	i = 0;
	while (argv[i] != NULL)
	{
		argv[i] = exp_env(argv[i], envp);
		i++;
	}
	return (0);
}
