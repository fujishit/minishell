#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
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
