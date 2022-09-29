#include "../include/push_swap.h"

void	ft_push(t_list **st1, t_list **st2)
{
	t_list	*tmp;

	if (!st1 || !*st1)
		return;
	tmp = *st1;
	*st1 = (*st1)->next;
	tmp->next = *st2;
	*st2 = tmp;
}

void	ft_rotate(t_list **list)
{
	t_list	*last;
	t_list	*tmp;

	if (!*list || !list || (ft_lstsize(*list) < 2))
		return;
	last = *list;
	*list = (*list)->next;
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = last;
	last->next = NULL;

}

void	ft_reverse(t_list **list)
{
	t_list	*tmp;
	t_list	*last;

	if (!list || !*list || (ft_lstsize(*list) < 2))
		return;
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	last = tmp;
	tmp = tmp->next;
	last->next = *list;
}

void	ft_sb(t_list **list)
{
	t_list	*tmp;
	t_list	*other;

	if (!list || !*list || (ft_lstsize(*list) < 2))
		return;
	other = (*list)->next->next;
	tmp = *list;
	*list = (*list)->next;
	(*list)->next = tmp;
	tmp->next = other;
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
