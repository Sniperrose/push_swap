#include "../include/push_swap.h"

void	free_stack(t_list **list)
{
	t_list	*tmp;

	if (!*list || !list)
		return;
	while (*list != NULL)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

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

void	ft_array(t_list **stack, int *min, int *max, int *pos)
{
	int	p_left;
	int	p_right;

	ft_min_max(stack, min, max);
	p_left = ft_index(stack, *min);
	p_right = ft_index(stack, *max);
	if (p_left > p_right)
		ft_swap_nbr(&p_left, &p_right);
	if (p_left > (ft_lstsize(*stack) - p_right))
		*pos = p_right;
	else
		*pos = p_left;
}

void	ft_push_b(t_list **stack_a, t_list **stack_b, int size)
{
	int	min;
	int max;
	int	pos;

	ft_array(stack_b, &min, &max, &pos);
	while (1)
	{
		if ((*stack_b)->content == min)
		{
			ft_pa(stack_a, stack_b);
			ft_ra(stack_a);
			break;
		}
		else if ((*stack_b)->content == max)
		{
			ft_pa(stack_a, stack_b);
			break;
		}
		else if (pos > (size - pos))
			ft_rrb(stack_b);
		else
			ft_rb(stack_b);
	}
}

void	ft_sort(t_list **stack_a, t_list **stack_b, int med)
{

	printf("before swap:\n");
	display(*stack_a);
	display(*stack_b);
	printf("median = %d\n", med);


	int	min;
	t_list	*tmp;
	int	index;
	int max;

	tmp = *stack_a;
	index = ft_index(stack_a, med);
	while(tmp->next != NULL && index > 0)
	{
		if ((tmp->content) > med)
			ft_ra(stack_a);
		else
		{
			*stack_a = (*stack_a)->next;
			ft_pb(&tmp, stack_b);
			index--;
		}
		tmp = *stack_a;
	}

	// printf("after swap : \nstack_a : ");
	// display(*stack_a);
	// printf("stack_b : ");
	// display(*stack_b);

	while (*stack_b != NULL)
		ft_push_b(stack_a, stack_b, ft_lstsize(*stack_b));
	while ((*stack_a)->content <= med)
		ft_ra(stack_a);


	while(tmp->content > med)
	{
		*stack_a = (*stack_a)->next;
		ft_pb(&tmp, stack_b);
		tmp = *stack_a;
	}

	// printf("after swap : \nstack_a : ");
	// display(*stack_a);
	// printf("stack_b : ");
	// display(*stack_b);

	while (*stack_b != NULL)
		ft_push_b(stack_a, stack_b, ft_lstsize(*stack_b));

	ft_min_max(stack_a, &min, &max);
	while ((*stack_a)->content > min)
		ft_ra(stack_a);
	printf("after alg : \nstack_a : ");
	display(*stack_a);
	printf("stack_b : ");
	display(*stack_b);



	return;
}

void	ft_pushswap(int	*nbrs, int size)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len;

	len = size;
	stack_a = NULL;
	stack_b = NULL;
	while (--len >= 0)
		ft_lstadd_front(&stack_a, ft_lstnew(nbrs[len]));
	if (ft_alreadysorted(&stack_a) == 1)
		return;
	else if (size == 2)
		ft_sa(&stack_a);
	else if (size == 3)
		ft_sort_3(&stack_a);
	else if (size == 4)
		ft_sort_4(&stack_a, &stack_b, ft_median(&stack_a, 4));
	else if (size == 5)
		ft_sort_5(&stack_a, &stack_b, ft_median(&stack_a, 5));
	else
		ft_sort(&stack_a, &stack_b, ft_median(&stack_a, size));
	free_stack(&stack_a);
	free_stack(&stack_b);
}


// void	ft_sort_4(t_list **stack_a, t_list **stack_b)
// {
// 	int	med;
// 	int	i;
// 	t_list *tmp;

// 	med = ft_median(stack_a, 4);
// 	i = 2;
// 	tmp = *stack_a;
// 	while (tmp != NULL && i > 0)
// 	{
// 		if (tmp->content < med)
// 		{
// 			ft_pb(stack_a, stack_b);
// 			i--;
// 		}
// 		else
// 			ft_ra(stack_a);
// 		tmp = *stack_a;
// 	}
// 	if ((*stack_a)->content > med)
// 	{
// 		if ((*stack_b)->content < ((*stack_b)->next)->content)
// 			ft_ss(stack_a, stack_b);
// 		else
// 			ft_sa(stack_a);
// 	}
// 	else
// 		ft_sb(stack_b);
// 	ft_pa(stack_a, stack_b);
// 	ft_pa(stack_a, stack_b);
// 	return;
// }

/*	printf("\n---sa---\n");
	ft_sa(&stack_a);
	display(stack_a);
	printf("---sb---\n");
	ft_sb(&stack_b);
	display(stack_b);

	printf("---ss---\n");
	ft_ss(&stack_a, &stack_b);
	display(stack_a);
	display(stack_b);

	printf("\n---pa---\n");
	ft_pa(&stack_a, &stack_b);
	display(stack_a);
	display(stack_b);
	printf("---pb---\n");
	ft_pb(&stack_a, &stack_b);
	display(stack_a);
	display(stack_b);

	printf("\n---ra---\n");
	ft_ra(&stack_a);
	display(stack_a);
	printf("---rb---\n");
	ft_rb(&stack_b);
	display(stack_b);
	printf("---rr---\n");
	ft_rr(&stack_a, &stack_b);
	display(stack_a);
	display(stack_b);

	printf("\n---rra---\n");
	ft_rra(&stack_a);
	display(stack_a);
	printf("---rrb---\n");
	ft_rrb(&stack_b);
	display(stack_b);
	printf("---rrr---\n");
	ft_rrr(&stack_a, &stack_b);
	display(stack_a);
	display(stack_b);
*/