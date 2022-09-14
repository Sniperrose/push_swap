#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	static int	tmp[10000];
	int		size;
	if (argc <= 1)
		return (0);
	/*while (argv[i])
	{
		tmp[valid] = ft_atoi(argv[i]);
		printf("%d\n", tmp[valid]);
		valid++;
		i++;
	}*/
	size = 0;
	printf("%d\n", argc);
	if ((size = ft_input(argv, &tmp[0])) == -1)
	{
		free(&tmp[0]);
		printf("Error\n");
		return (0);
	}
	ft_pushswap(&tmp[0], size);
	return (0);
}
