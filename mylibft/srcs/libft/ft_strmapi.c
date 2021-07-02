#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	len;

	if (s == NULL || f == NULL)
		return (0);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
	{
		ret[len] = f(len, s[len]);
		len++;
	}
	ret[len] = '\0';
	return (ret);
}
