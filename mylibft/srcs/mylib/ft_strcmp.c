#include "mylib.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (ss1[i] != '\0' && ss2[i] != '\0' && ss1[i] == ss2[i])
		i++;
	return (ss1[i] - ss2[i]);
}
