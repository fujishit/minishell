#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	char			c;
	int				i;

	i = 1000000000;
	if (n == 0)
		write(fd, "0", 1);
	if (n == 0 || fd < 0)
		return ;
	if (n < 0)
	{
		un = (unsigned int)n * -1;
		write(fd, "-", 1);
	}
	else
		un = (unsigned int)n;
	while (un / i == 0 && i > 0)
		i /= 10;
	while (i > 0)
	{
		c = un / i + '0';
		write(fd, &c, 1);
		un %= i;
		i /= 10;
	}
}
