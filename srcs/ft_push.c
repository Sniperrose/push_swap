/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:18:39 by galtange          #+#    #+#             */
/*   Updated: 2022/09/29 20:18:43 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push(t_list **st1, t_list **st2)
{
	t_list	*tmp;

	if (!st1 || !*st1)
		return ;
	tmp = *st1;
	*st1 = (*st1)->next;
	tmp->next = *st2;
	*st2 = tmp;
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}
