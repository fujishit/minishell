#include "libft.h"

static size_t	ft_getsize(char const *s, char c)
{
	size_t	size;

	while (*s == c && *s != '\0')
		s++;
	size = 0;
	if (s[0] == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s != c)
			size++;
		while (*s != c && *s != '\0')
			s++;
		while (*s == c && *s != '\0')
			s++;
	}
	return (size);
}

static size_t	ft_getlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static char	**ft_free(char **ret, size_t count)
{
	while (ret[count--])
		free(ret[count]);
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	count;
	size_t	len;

	if (s == NULL)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (ft_getsize(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	count = 0;
	while (*s != '\0')
	{
		len = (ft_getlen(s, c) + 1);
		ret[count] = (char *)malloc(sizeof(char) * (len));
		if (ret[count] == NULL)
			return (ft_free(ret, count));
		ft_strlcpy(ret[count++], s, len);
		while (*s != c && *s != '\0')
			s++;
		while (*s == c && *s != '\0')
			s++;
	}
	ret[count] = NULL;
	return (ret);
}
