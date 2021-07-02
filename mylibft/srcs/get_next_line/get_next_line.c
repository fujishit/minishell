#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*save;
	int			ret;

	ret = 0;
	if (line == NULL || fd < 0 || 256 <= fd || BUFFER_SIZE <= 0)
		return (-1);
	if (save == NULL || (gnl_strchr(save, '\n')) == NULL)
		ret = gnl_read(fd, &save);
	if (ret != -1)
	{
		if (save == NULL)
		{
			line[0] = malloc(1);
			line[0][0] = '\0';
			return (0);
		}
		ret = gnl_save(&save, line);
	}
	if (ret == 0)
	{
		free(save);
		save = NULL;
	}
	return (ret);
}

int	gnl_read(int fd, char **save)
{
	int		ret;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (buf == NULL)
		return (-1);
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
			break ;
		buf[ret] = '\0';
		tmp = *save;
		if (*save == NULL)
			*save = gnl_strdup(buf);
		else
			*save = gnl_strjoin(*save, buf);
		free(tmp);
		if (*save == NULL)
			return (free_return(buf, -1));
		else if (gnl_strchr(*save, '\n') != NULL)
			break ;
	}
	return (free_return(buf, ret));
}

int	free_return(void *buf, int ret)
{
	free(buf);
	return (ret);
}

int	gnl_save(char **save, char **line)
{
	char	*tmp;
	int		ret;
	size_t	len;

	ret = 1;
	if (gnl_strchr(*save, '\n') == NULL)
		ret = 0;
	len = 0;
	while (save[0][len] != '\n' && save[0][len] != '\0')
		len++;
	line[0] = (char *)malloc(sizeof(char) * (len + 1));
	if (line[0] == NULL)
		return (-1);
	line[0][0] = '\0';
	tmp = gnl_strdup(*save + len + ret);
	if (tmp == NULL)
	{
		free(line[0]);
		line[0] = NULL;
		return (-1);
	}
	gnl_strlcpy(line[0], *save, len + 1);
	free(*save);
	*save = tmp;
	return (ret);
}
