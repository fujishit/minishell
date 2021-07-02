#include "mylib.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*ret;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	if (n < len)
		len = n;
	ret = (char *)malloc((sizeof(char) * len) + 1);
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
