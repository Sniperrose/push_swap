/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 12:05:27 by galtange          #+#    #+#             */
/*   Updated: 2022/10/08 12:32:30 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_getvalue(t_list **stack_b, int *min, int *max, unsigned int *pos)
{
	t_list	*tmp;
	int		size;
	int		i;

	i = 0;
	tmp = *stack_b;
	*min = (*stack_b)->content;
	*max = (*stack_b)->content;
	size = ft_lstsize(*stack_b);
	while (i < size)
	{
		if (*min > tmp->content)
		{
			*min = tmp->content;
			pos[0] = i;
		}
		if (*max < tmp->content)
		{
			*max = tmp->content;
			pos[1] = i;
		}
		tmp = tmp->next;
		i++;
	}
}

unsigned int	ft_min(int a, int b)
{
	if (a > b)
	{
		return (b);
	}
	return (a);
}

unsigned int	ft_cntr(int size, unsigned int *pos, int *f_ra, int *f_rrb)
{
	unsigned int	cntr;

	cntr = ft_min(ft_min(pos[0], pos[1]), ft_min(size - pos[0], size - pos[1]));
	if (cntr == pos[1])
	{
		*f_ra = 0;
		*f_rrb = 0;
	}
	else if (cntr == (size - pos[1]))
	{
		*f_ra = 0;
		*f_rrb = 1;
	}
	else if (cntr == pos[0])
	{
		*f_ra = 1;
		*f_rrb = 0;
	}
	else if (cntr == (size - pos[0]))
	{
		*f_ra = 1;
		*f_rrb = 1;
	}
	return (cntr);
}

int	ft_minmax(t_list **stack_b, int *flag_ra, int *falg_rrb)
{
	int				min;
	int				max;
	unsigned int	cntr;
	unsigned int	pos[2];

	pos[0] = 0;
	pos[1] = 0;
	cntr = 0;
	ft_getvalue(stack_b, &min, &max, pos);
	cntr = ft_cntr(ft_lstsize(*stack_b), pos, flag_ra, falg_rrb);
	return (cntr);
}