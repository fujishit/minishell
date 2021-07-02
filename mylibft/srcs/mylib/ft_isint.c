#include "mylib.h"

static int	ft_intdigit(int num)
{
	size_t	digit;

	digit = 0;
	num = num / 10;
	while (num > 0)
	{
		num = num / 10;
		digit++;
	}
	return (digit + 1);
}

static int	ft_strdigit(char *num)
{
	size_t	digit;

	digit = 0;
	while (num[digit] != '\0')
	{
		if (ft_isdigit(num[digit]) == 0)
			return (-1);
		digit++;
	}
	return (digit);
}

int	ft_isint(char *num)
{
	int	digit;
	int	negative;

	digit = 0;
	negative = 0;
	if (num[0] == '\0')
		return (-1);
	else if (num[0] == '-')
		negative = 1;
	digit = ft_strdigit(num + negative);
	if (digit == -1)
		return (-1);
	else if (ft_intdigit(INT_MAX) < digit)
		return (-1);
	return (ft_intcheck(num));
}
