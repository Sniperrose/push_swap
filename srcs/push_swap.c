/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:52:12 by galtange          #+#    #+#             */
/*   Updated: 2022/10/08 12:52:13 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_newstack(int *nbrs, int size)
{
	int	i;
	t_list	*stack;

	i = size;
	stack = NULL;
	while (--i >= 0)
	{
		if (!ft_lstadd_front(&stack, ft_lstnew(nbrs[i])))
			return (NULL);

	}
	if (!stack)
		return (NULL);
	return(stack);
}

void	ft_pushswap(int	*nbrs, int size)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = ft_newstack(nbrs, size);
	if (!stack_a)
		return ;
	stack_b = NULL;
	if (ft_alreadysorted(&stack_a) == 1)
		return ;
	else if (size == 2)
		ft_sa(&stack_a);
	else if (size == 3)
		ft_sort_3(&stack_a);
	else if (size == 4)
		ft_sort_4(&stack_a, &stack_b, ft_median(&stack_a, 4));
	else if (size == 5)
		ft_sort_5(&stack_a, &stack_b, ft_median(&stack_a, 5));
	else if (size <= 100)
		ft_sort(&stack_a, &stack_b, ft_median(&stack_a, size));
	else
		ft_sort_big(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}