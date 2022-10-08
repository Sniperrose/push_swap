/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:34:17 by galtange          #+#    #+#             */
/*   Updated: 2022/10/08 12:34:33 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_revrotate(t_list **list)
{
	t_list	*tmp;
	t_list	*other;

	if (!list || !*list || (ft_lstsize(*list) < 2))
		return ;
	other = *list;
	tmp = (*list)->next;
	while (other->next->next != NULL)
	{	
		other = other->next;
		tmp = tmp->next;
	}
	other->next = NULL;
	tmp->next = *list;
	*list = tmp;
}

void	ft_rra(t_list **stack_a)
{
	if (!stack_a || (ft_lstsize(*stack_a) < 2))
		return ;
	ft_revrotate(stack_a);
	ft_putstr_fd("rra\n", 1);
	g_cntr++;
}

void	ft_rrb(t_list **stack_b)
{
	if (!stack_b || (ft_lstsize(*stack_b) < 2))
		return ;
	ft_revrotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
	g_cntr++;
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) && (ft_lstsize(*stack_b) < 2))
		return ;
	ft_revrotate(stack_a);
	ft_revrotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
	g_cntr++;
}
