#include "get_next_line.h"

char	*gnl_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*gnl_strdup(const char *s)
{
	char	*ret;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	ret = (char *)malloc((len * sizeof(char)) + 1);
	if (ret == NULL)
		return (0);
	ret[len] = '\0';
	while (len--)
		ret[len] = s[len];
	return (ret);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ((gnl_strlen(s1) + gnl_strlen(s2)) + 1);
	ret = (char *)malloc((sizeof(char) * len));
	if (ret == NULL)
		return (0);
	len = 0;
	while (*s1 != '\0')
		ret[len++] = *s1++;
	while (*s2 != '\0')
		ret[len++] = *s2++;
	ret[len] = '\0';
	return (ret);
}

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	ret;

	ret = 0;
	if (!dst || !src)
		return (0);
	while (src[ret] != '\0')
		ret++;
	if (size == 0)
		return (ret);
	while (size-- > 1 && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}
