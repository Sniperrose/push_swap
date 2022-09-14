#include "../include/push_swap.h"

void	ft_pushswap(int *stack, int size)
{
	int	i = 0;

	while (stack && i < size)
	{
		printf("%d\n", stack[i]);
		i++;
	}
}

