#include "../include/push_swap.h"

void	ft_sa(t_list **list)
{
	t_list	*tmp;
	t_list	*other;

	if (!list || (ft_lstsize(*list) < 2) || !*list)
		return;
	other = (*list)->next->next;
	tmp = *list;
	*list = (*list)->next;
	(*list)->next = tmp;
	tmp->next = other;
}
