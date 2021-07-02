#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ret;

	ret = (unsigned char *)b;
	while (len--)
		*ret++ = (unsigned char)c;
	return (b);
}
