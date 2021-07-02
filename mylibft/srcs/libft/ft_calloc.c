#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = (void *)malloc(nmemb * size);
	if (ret == NULL)
		return (0);
	ft_bzero(ret, nmemb * size);
	return (ret);
}
