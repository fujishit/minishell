#include "libft.h"

int	ft_isalnum(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
