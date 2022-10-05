/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_part1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:29:20 by galtange          #+#    #+#             */
/*   Updated: 2022/10/05 19:02:06 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_alreadysorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->content > (tmp->next)->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_min_max(t_list **stack, int *min, int *max)
{
	t_list	*tmp;

	tmp = *stack;
	*min = tmp->content;
	*max = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < *min)
			*min = tmp->content;
		if (tmp->content > *max)
			*max = tmp->content;
		tmp = tmp->next;
	}
}

void	ft_sort_3(t_list **stack)
{
	int	min;
	int	max;

	ft_min_max(stack, &min, &max);
	if ((*stack)->content == max)
	{
		ft_ra(stack);
		if (!ft_alreadysorted(stack))
			ft_sa(stack);
	}
	else if ((*stack)->content == min)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
	else if (((*stack)->next)->content == max)
		ft_rra(stack);
	else
		ft_sa(stack);
}

void	ft_sort_4(t_list **stack_a, t_list **stack_b, int med)
{
	int		i;
	t_list	*tmp;

	i = 2;
	tmp = *stack_a;
	while (tmp != NULL && i > 0)
	{
		if (tmp->content < med)
		{
			ft_pb(stack_a, stack_b);
			i--;
		}
		else
			ft_rra(stack_a);
		tmp = *stack_a;
	}
	if ((*stack_a)->content > med)
		ft_sa(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	if (((*stack_a)->content > ((*stack_a)->next)->content))
		ft_sa(stack_a);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b, int med)
{
	int		i;
	t_list	*tmp;

	i = 2;
	tmp = *stack_a;
	while (tmp != NULL && i > 0)
	{
		if (tmp->content < med)
		{
			ft_pb(stack_a, stack_b);
			i--;
		}
		else
			ft_rra(stack_a);
		tmp = *stack_a;
	}
	ft_sort_3(stack_a);
	if (((*stack_b)->content < ((*stack_b)->next)->content))
		ft_sb(stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
