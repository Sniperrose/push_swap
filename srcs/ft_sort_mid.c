/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:35:13 by galtange          #+#    #+#             */
/*   Updated: 2022/10/08 12:48:25 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_back(t_list **stack_a, t_list **stack_b)
{
	int	flag_ra;
	int	flag_rrb;
	int	i;

	i = ft_minmax(stack_b, &flag_ra, &flag_rrb);
	while (i > 0)
	{
		if (flag_rrb)
			ft_rrb(stack_b);
		else if (!flag_rrb)
			ft_rb(stack_b);
		i--;
	}
	ft_pa(stack_a, stack_b);
	if (flag_ra)
		ft_ra(stack_a);
	flag_ra = 0;
	flag_rrb = 0;
}

void	ft_algo_left(t_list **stack_a, t_list **stack_b, int med)
{
	t_list	*tmp;
	int		ind;

	tmp = *stack_a;
	ind = ft_lstsize(*stack_a) / 2;
	while (tmp->next != NULL && ind >= 0)
	{
		if (tmp->content <= med)
		{
			ft_pb(stack_a, stack_b);
			ind--;
		}
		else if (tmp->content > med)
			ft_ra(stack_a);
		tmp = *stack_a;
	}
	while (*stack_b != NULL)
		ft_push_back(stack_a, stack_b);
	while ((*stack_a)->content <= med)
		ft_ra(stack_a);
}

void	ft_algo_right(t_list **stack_a, t_list **stack_b, int med)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->content > med)
	{
		*stack_a = (*stack_a)->next;
		ft_pb(&tmp, stack_b);
		tmp = *stack_a;
	}
	while (*stack_b != NULL)
		ft_push_back(stack_a, stack_b);
	while ((*stack_a)->content > med)
		ft_ra(stack_a);
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int med)
{
	ft_algo_left(stack_a, stack_b, med);
	ft_algo_right(stack_a, stack_b, med);
}
