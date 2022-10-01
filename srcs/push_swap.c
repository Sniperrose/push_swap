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

void	ft_pushswap(int	*nbrs, int size)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	i;

	stack_a = NULL;
	stack_b = NULL;
	i = size - 1;
	while (i >= 0)
		ft_lstadd_front(&stack_a, ft_lstnew(nbrs[i--]));
	
	printf("stack_a : ");
	display(stack_a);
	printf("stack_b : ");
	display(stack_b);


	ft_median(&stack_a, ft_lstsize(stack_a));
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
	free_stack(&stack_a);
	free_stack(&stack_b);
}
