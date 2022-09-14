#include "../include/push_swap.h"

int	ft_dupcheck(int *tmp, int n, int i)
{
	int	j = 0;
	while (j <= i)
	{
		if (tmp[j] == n)
			return (-1);
		j++;
	}
	return (0);
}
long int	ft_atoi(char *nptr)
{
	int	i;
	int	sign;
	long	num;

	i = 0;
	num = 0;
	sign = 1;
	while ((nptr[i] > 7 && nptr[i] < 14) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] > '9' || nptr[i] < '0')
			return (-21474836480);
		num = 10 * num + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_input(char **argv, int *tmp)
{
	int	i = 0;
	long int	n = 0;

	while (argv[i + 1])
	{
		n = ft_atoi(argv[i + 1]);
		if (n < -2147483648 || n > 2147483647 || 
				ft_dupcheck(&tmp[0], n, i) != 0)
			return (-1);
		tmp[i] = n;
		i++;
	}
	return (i);
}
