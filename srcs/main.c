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
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num = 10 * num + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

int	*ft_char2int(char **tmp, int size)
{
	int	i = 0;
	int	*nbrs;
	long long	nb = 0;	

	nbrs = (int *)malloc(size * sizeof(int));
	if (!nbrs || !tmp)
		return (NULL);
	while (tmp[i] && i < size)
	{
		nb = ft_atoi(tmp[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			free(nbrs);
			return (NULL);
		}
		nbrs[i] = (int)nb;
		i++;
	}
	return (nbrs);
}

char	**ft_split2(int	size, char **nbrs)
{
	char	**result;
	int	line;

	result = (char **)malloc((size + 1) * sizeof(char *));
	if (!nbrs || !result)
		return(NULL);
	line = 0;
	while (line < size)
	{
		result[line] = ft_substr(nbrs[line], 0, ft_strlen(nbrs[line]));
		if (!result[line] || ft_isalpha(result[line][0]))
		{
			ft_free(result, line);
			return (NULL);
		}
		line++;
	}
	result[line] = NULL;
	return (result);
}

int	ft_dupcheck(int *nbrs, int size)
{
	int	i;
	int	j;

	i = 0;
	while(i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nbrs[i] == nbrs[j])
				return 0;
			j++;
		}
		i++;
	}
	return (1);
}

int main (int argc, char **argv)
{
	char	**all;
	int	*nbrs;
	int	i = 0;
	
	if (argc >= 1)
	{
		all = ft_split2(argc - 1, argv + 1);
		if (!all)
			return (write(1, "Error\n", 6));
		nbrs = ft_char2int(all, argc - 1);
		if (!nbrs || !ft_dupcheck(nbrs, argc - 1))
			return (write(1, "Error\n", 6));
		i = 0;
		while (i < (argc - 1))
			printf("%d\n", nbrs[i++]);
		free(nbrs);
		ft_free(all, i);
	}
}

/* ver2
int main(int argc, char	**argv)
{
	char	*all;
	int		i = 0;
	char	**tmp;
	int	*nbrs;

	if (argc >= 1)
	{
		all = ft_joinall(argc - 1, argv + 1);
		if (!all)
		{
			free(all);i
			ft_putstr_fd("Error\n", 1);
		}
		tmp = ft_split(all, ' ');
		while (tmp[i])
		{	
			ft_putstr_fd(tmp[i++], 1);
			ft_putstr_fd("\n", 1);
		
		nbrs = (int *)malloc((i + 1) * sizeof(int));
		if (!nbrs)
			return (0);
		ft_char2int(tmp, nbrs);
		i = 0;
		while (nbrs[i])
			printf("%d\n", nbrs[i++]);
		free(all);
		ft_free(tmp, i);
		free(nbrs);

	}
	return (0);
}
*/
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
