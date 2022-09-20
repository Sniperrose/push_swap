#include "../include/push_swap.h"

int	ft_isalpha(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (1);
	else
		return (0);
}

long long	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long long	num;

	i = 0;
	num = 0;
	sign = 1;


	while ((nptr[i] > 7 && nptr[i] < 14) || (nptr[i] == 32))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (47 < nptr[i] && nptr[i] < 58)
	{
		num = 10 * num + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_char2int(int *numbers, char *all)
{
	int	i = 0;
	long long	nbr;
	char	**split;
	
	split = ft_split(all, ' ');
	while(split)
	{
		if (ft_isalpha(split[i][0]) == 0)
		{
			ft_free(split, i);
			free(numbers);
			return (1);
		}
		nbr = ft_atoi(split[i]);
		if (2147483647 < nbr || nbr < -2147483648)
			return (1);
		numbers[i] = nbr;
		i++;
	}
	return (0);
}

int main(int argc, char	**argv)
{
	char	*all;
	int		i = 0;
	int		*numbers = NULL;

	if (argc >= 1)
	{
		all = ft_joinall(argc - 1, argv + 1);
		if (!all)
		{
			free(all);
			ft_putstr_fd("Error\n", 1);
		}
		numbers = malloc((argc - 1) * sizeof(int));
		if (!numbers)
		{
			free(numbers);
			return (0);
		}
		if(ft_char2int(numbers, all) == 1)
		{
			free(all);
			ft_putstr_fd("error\n", 1);
			return (0);
		}		
		while (i < argc - 1)
		{
			printf("%d\n", numbers[i]);
			i++;
		}
	}
	return (0);
}

// int main(int argc, char **argv)
// {
// 	static int	tmp[10000];
// 	int		size;
// 	if (argc <= 1)
// 		return (0);
// 	/*while (argv[i])
// 	{
// 		tmp[valid] = ft_atoi(argv[i]);
// 		printf("%d\n", tmp[valid]);
// 		valid++;
// 		i++;
// 	}*/
// 	size = 0;
// 	printf("%d\n", argc);
// 	if ((size = ft_input(argv, &tmp[0])) == -1)
// 	{
// 		free(&tmp[0]);
// 		printf("Error\n");
// 		return (0);
// 	}
// 	ft_pushswap(&tmp[0], size);
// 	return (0);
// }
