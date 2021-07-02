#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (dest[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
