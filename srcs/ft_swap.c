/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:38:55 by galtange          #+#    #+#             */
/*   Updated: 2022/10/08 12:51:46 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_list **list)
{
	t_list	*other;
	t_list	*tmp;

	if (!*list || !list || (ft_lstsize(*list) < 2))
		return ;
	other = (*list)->next->next;
	tmp = *list;
	*list = (*list)->next;
	(*list)->next = tmp;
	tmp->next = other;
}

void	ft_sa(t_list **stack_a)
{
	if (!*stack_a || (ft_lstsize(*stack_a) < 2))
		return ;
	ft_swap(stack_a);
	ft_putstr_fd("sa\n", 1);
	g_cntr++;
}	

void	ft_sb(t_list **stack_b)
{
	if (!*stack_b || (ft_lstsize(*stack_b) < 2))
		return ;
	ft_swap(stack_b);
	ft_putstr_fd("sb\n", 1);
	g_cntr++;
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putstr_fd("ss\n", 1);
	g_cntr++;
}
