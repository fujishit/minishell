#include "libft.h"
#include <stdio.h>
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (s == NULL)
		return (0);
	if (ft_strlen(s) < start || len <= 0)
	{
		ret = (char *)malloc(1);
		if (ret == NULL)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ret = (char *)malloc((size_t)(len + 1) * sizeof(char));
	if (ret == NULL)
		return (NULL);
	i = 0;
	ret[i] = s[start + i];
	while (++i < len)
		ret[i] = s[start + i];
	ret[i] = '\0';
	return (ret);
}
