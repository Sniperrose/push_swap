#include "../include/push_swap.h"

int main(int argc, char	**argv)
{
	char	*all;
	char	**split;
	int		i = 0;
	if (argc >= 1)
	{
		all = ft_joinall(argc - 1, argv + 1);
		if (!all)
		{
			free(all);
			ft_putstr_fd("Error\n", 1);
		}
		split = ft_split(all, ' ');
		if (!split)
		{
			ft_free(split, argc - 1);
			ft_putstr_fd("Error\n", 1);
		}
		while(i < (argc - 1))
		{
			ft_putstr_fd(split[i], 1);
			ft_putstr_fd("\n", 1);
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
