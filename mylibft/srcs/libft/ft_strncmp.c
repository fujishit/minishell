#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				ret;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ret = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (n-- && ret == 0 && ss1[i] != '\0')
	{
		ret = ss1[i] - ss2[i];
		i++;
	}
	return (ret);
}
