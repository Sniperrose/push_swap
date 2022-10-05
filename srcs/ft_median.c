#include "../include/push_swap.h"

void ft_swap_nbr(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_med(int *tmp, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp[i] > tmp[j])
				ft_swap_nbr(&tmp[i], &tmp[j]);
			j++;
		}
		i++;
	}
	// printf("sorted area : ");
	// i = 0;
	// while (i < size)
	// {
	// 	printf("%d->", tmp[i]);
	// 	i++;
	// }
	// printf("NULL\n");
	
	return (tmp[size/2]);
}

int	ft_median(t_list **stack, int size)
{
	int	i;
	int	nbrs[size];
	int med;
	t_list	*tmp;
	
	if (!*stack || !stack)
		return (0);
	tmp = *stack;
	i = 0;
	while (i < size)
	{
		nbrs[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	med = ft_med(&nbrs[0], size);
	return (med);
}