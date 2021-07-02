#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ret;
	unsigned const char	*retsrc;

	if (dest == src)
		return (dest);
	ret = (unsigned char *)dest;
	retsrc = (unsigned char *)src;
	while (n--)
		*ret++ = *retsrc++;
	return (dest);
}
