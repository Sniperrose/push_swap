/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:35:34 by galtange          #+#    #+#             */
/*   Updated: 2022/10/08 13:35:36 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    ft_medianbig(t_list **stack, int *min, int *max, int *medians)
{
    t_list *tmp;
    int     size;
    int     *nbrs;
    int     i;

    size = ft_lstsize(*stack);
    nbrs = malloc(size * sizeof(int));
    if (!nbrs || !*stack || !stack)
        return ;
    tmp = *stack;
    i = 0;
    while (i < size)
    {
        nbrs[i] = tmp->content;
        tmp = tmp->next;
        i++;
    }
    nbrs = ft_sort_nbrs(&nbrs[0], size);
    *min = nbrs[0];
    *max = nbrs[i - 1];
    medians[0] = nbrs[size/4];
    medians[1] = nbrs[size/2];
    size = size/2 + size/4;
    medians[2] = nbrs[size];
    free (nbrs);
}

void	ft_push_backtest(t_list **stack_a, t_list **stack_b)
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

void	ft_algo_lefttest(t_list **stack_a, t_list **stack_b, int min, int max)
{
	t_list	*tmp;
	int		ind;

	tmp = *stack_a;
	ind = ft_lstsize(*stack_a) / 4;
	while (tmp->next != NULL && ind >= 0)
	{
		if (tmp->content >= min && tmp->content <= max)
		{
			ft_pb(stack_a, stack_b);
			ind--;
		}
		else
			ft_ra(stack_a);
		tmp = *stack_a;
	}
	while (*stack_b != NULL)
		ft_push_backtest(stack_a, stack_b);
	while ((*stack_a)->content <= max && (*stack_a)->content >= min)
		ft_ra(stack_a);
}

// void	ft_algo_righttest(t_list **stack_a, t_list **stack_b, int med)
// {
// 	t_list	*tmp;

// 	tmp = *stack_a;
// 	while (tmp->content > med)
// 	{
// 		*stack_a = (*stack_a)->next;
// 		ft_pb(&tmp, stack_b);
// 		tmp = *stack_a;
// 	}
// 	while (*stack_b != NULL)
// 		ft_push_backtest(stack_a, stack_b);
// 	while ((*stack_a)->content > med)
// 		ft_ra(stack_a);
// }

// void	ft_sort_test(t_list **s_a, t_list **s_b, int min, int max)
// {
// 	ft_algo_lefttest(s_a, s_b, min, max);
// 	// ft_algo_righttest(stack_a, stack_b, med);
// }

void	ft_sort_big(t_list **stack_a, t_list **stack_b)
{
    int medians[3];
    int min;
    int max;

    min = 0;
    max = 0;
    medians[0] = 0;
    medians[1] = 0;
    medians[2] = 0;
    ft_medianbig(stack_a, &min, &max, medians);
    ft_algo_lefttest(stack_a, stack_b, min, medians[0]);
    ft_algo_lefttest(stack_a, stack_b, medians[0], medians[1]);
    ft_algo_lefttest(stack_a, stack_b, medians[1], medians[2]);
    ft_sort(stack_a, stack_b, medians[2]);
    printf("min = %d, max = %d, m1 = %d, m2 = %d, m3 = %d\n", min, max, medians[0], medians[1], medians[2]);
}
