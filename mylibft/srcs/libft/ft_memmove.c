#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ret;
	unsigned const char	*retsrc;

	ret = (unsigned char *)dest;
	retsrc = (unsigned const char *)src;
	if (ret == retsrc)
		return (dest);
	if (ret < retsrc)
		while (n--)
			*ret++ = *retsrc++;
	else
		while (n--)
			ret[n] = retsrc[n];
	return (dest);
}
