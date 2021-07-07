#include "minishell.h"

//meta文字が見つかるまで(issep関数で0が返ってくる)の文字列をコピーする関数
static char	*lex_arg(char *line, size_t *i)
{
	char	*arg;
	size_t	n;
	int		flag;

	n = *i;
	flag = 0;
	while (flag == 0 && ms_issep(line[*i]) == 0
		|| flag != 0 && ms_issep(line[*i]) != -1)
	{
		if (line[*i] == '\'' || line[*i] == '\"')
		{
			if (flag == line[*i])
				flag = 0;
			else if (flag == 0)
				flag = line[*i];
		}
		(*i)++;
	}
	arg = ft_substr(line, n, ((*i) - n));
	while (line[*i] == ' ')
		(*i)++;
	return (arg);
}

//meta文字が見つかったら(issep関数で1が返ってくる)meta文字列をコピーする関数
static char	*lex_meta(char *line, size_t *i)
{
	char	*meta;
	size_t	n;

	n = *i;
	while (ms_issep(line[*i]) == 1)
		(*i)++;
	if (n < *i)
		meta = ft_substr(line, n, ((*i) - (n + 1)));
	else
		meta = "\0";
	while (line[*i] == ' ')
		(*i)++;
	return (meta);
}

//渡されたコマンドを分けて返す関数
int	ms_lexer(char *line, t_list **lex_cmd)
{
	size_t	i;
	t_list	*new;

	i = 0;
	*lex_cmd = ft_lstnew("\0");
	while (line[i] != '\0')
	{
		while (ms_issep(line[i]) == 0)
		{
			new = ft_lstnew(lex_arg(line, &i));
			ft_lstadd_back(lex_cmd, new);
			if (new == NULL || new->content == NULL)
				return (-1);
		}
		new = ft_lstnew(lex_meta(line, &i));
		ft_lstadd_back(lex_cmd, new);
		if (new == NULL || new->content == NULL)
			return (-1);
	}
	return (0);
}
