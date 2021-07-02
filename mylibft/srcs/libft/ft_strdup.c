#include "libft.h"

char	*ft_strdup(const char *s)
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
