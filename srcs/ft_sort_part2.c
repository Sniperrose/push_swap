#include "../include/push_swap.h"

// int *ft_nbrs(t_list **stack, int size)
// {
//     int *nbrs;
//     t_list  *tmp;

//     if (!stack || !*stack)
//         return (NULL);
//     nbrs = malloc(size * sizeof(int));
//     if (!nbrs)
//         return (NULL);
//     tmp = *stack;
//     while (tmp != NULL)
//     {
//         *nbrs = tmp->content;
//         tmp = tmp->next;
//         nbrs++;
//     }
//     return (&nbrs[0]);
// }

// int ft_bestpos(int *nbrs, int *min, int *max, int size)
// {
//     int p_left;
//     int p_right;
//     int i;

//     p_left = 0;
//     p_right = 0;
//     *min = 0;
//     *max = 0;
//     i = 0;
//     while (i < size)
//     {
//         if (*min >= nbrs[i])
//         {
//             *min = nbrs[i];
//             p_left = i;
//         }
//         if (*max <= nbrs[i])
//         {
//             *max = nbrs[i];
//             p_right = i;
//         }
//         i++;
//     }
//     if (p_left > p_right)
//         ft_swap_nbr(&p_left, &p_right);
//     printf("R = %d, L = %d\n", p_right, p_left);
//     if (p_left < (i - p_right))
//         return (p_left);
//     else
//         return (p_right);

// }

// void    ft_minmax(t_list **stack, int *min, int *max, int *best_pos)
// {
//     int *nbrs;
//     int size;

//     size = ft_lstsize(*stack);
//     nbrs = ft_nbrs(stack, size);
//     if (!nbrs)
//         return ;
//     // best_pos = 0;
//     // min = 0;
//     // max = 0;
//     *best_pos = ft_bestpos(&nbrs[0], min, max, size);
//     free(nbrs);
//     return ;
// }

int	ft_index(t_list **stack, int med)
{
	t_list	*tmp;
	int	i;

	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		if ((tmp->content) <= med)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_minmax(t_list **stack, int *min, int *max, int *best_pos)
{
	int	p_left;
	int	p_right;

	ft_min_max(stack, min, max);
	p_left = ft_index(stack, *min);
	p_right = ft_index(stack, *max);
    
    if (p_left < p_right)
        ft_swap_nbr(&p_left, &p_right);
	
    if (p_left > (ft_lstsize(*stack) - p_right))
		*best_pos = p_right;
	else
		*best_pos = p_left;
}

void	ft_push_back(t_list **stack_a, t_list **stack_b, int size)
{
	int	min;
	int max;
	int	pos;

    ft_minmax(stack_b, &min, &max, &pos);
    if (size == 1)
        ft_pa(stack_a, stack_b);
    else if (size == 2 && (*stack_b)->content > (*stack_b)->next->content)
        ft_pa(stack_a, stack_b);
    else if (size == 2 && (*stack_b)->content < (*stack_b)->next->content)
    {
        ft_pa(stack_a, stack_b);
        ft_ra(stack_a);
    }
	else if ((*stack_b)->content == min)
	{
		ft_pa(stack_a, stack_b);
		ft_ra(stack_a);
	}
	else if ((*stack_b)->content == max)
		ft_pa(stack_a, stack_b);
	else if (pos > (size / 2))
		ft_rrb(stack_b);
	else
		ft_rb(stack_b);
    return;
}

void    ft_algo_left(t_list **stack_a, t_list **stack_b, int med)
{
    t_list  *tmp;
    int     ind;

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
		ft_push_back(stack_a, stack_b, ft_lstsize(*stack_b));
    while ((*stack_a)->content <= med)
		ft_ra(stack_a);
}

void    ft_algo_right(t_list **stack_a, t_list **stack_b, int med)
{
    t_list  *tmp;

    tmp = *stack_a;
	while(tmp->content > med)
	{
		*stack_a = (*stack_a)->next;
		ft_pb(&tmp, stack_b);
		tmp = *stack_a;
	}
    while (*stack_b != NULL)
		ft_push_back(stack_a, stack_b, ft_lstsize(*stack_b));
    while ((*stack_a)->content > med)
		ft_ra(stack_a);
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int med)
{
    printf ("med = %d\n", med);
    ft_algo_left(stack_a, stack_b, med);
    ft_algo_right(stack_a, stack_b, med);
}
