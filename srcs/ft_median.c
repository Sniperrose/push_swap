/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:45:22 by galtange          #+#    #+#             */
/*   Updated: 2022/10/08 11:45:31 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap_nbr(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*ft_sort_nbrs(int *tmp, int size)
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
	return (&tmp[0]);
}

int	ft_median(t_list **stack, int size)
{
	int		i;
	int		*nbrs;
	int		med;
	t_list	*tmp;

	nbrs = malloc(size * sizeof(int));
	if (!*stack || !stack || !nbrs)
		return (0);
	tmp = *stack;
	i = 0;
	while (i < size)
	{
		nbrs[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	nbrs = ft_sort_nbrs(&nbrs[0], size);
	med = nbrs[size/2];
	free(nbrs);
	return (med);
}
