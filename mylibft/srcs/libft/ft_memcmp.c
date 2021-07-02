#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*dest;
	unsigned const char	*src;

	dest = s1;
	src = s2;
	while (n--)
	{
		if (*dest != *src)
			return (*dest - *src);
		dest++;
		src++;
	}
	return (0);
}
