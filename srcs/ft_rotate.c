/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:21:58 by galtange          #+#    #+#             */
/*   Updated: 2022/09/29 20:22:01 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate(t_list **list)
{
	t_list	*last;
	t_list	*tmp;

	if (!*list || !list || (ft_lstsize(*list) < 2))
		return ;
	last = *list;
	*list = (*list)->next;
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = last;
	last->next = NULL;
}

void	ft_ra(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) < 2)
		return ;
	ft_rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
	// g_cntr++;
}

void	ft_rb(t_list **stack_b)
{
	if (ft_lstsize(*stack_b) < 2)
		return ;
	ft_rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
	// g_cntr++;
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) && (ft_lstsize(*stack_b) < 2))
		return ;
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
	// g_cntr++;
}
