#include "../include/push_swap.h"

t_list	*ft_lstnew(int	content)
{
	t_list	*newNode;

	newNode = (t_list *)malloc(sizeof(t_list));
	if (!newNode)
		return (0);
	newNode->content = content;
	newNode->next = NULL;
	return (newNode);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return;
	}
	if (!new)
		return;
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	size;
	t_list	*tmp;

	size = 0;
	if(!lst)
		return (0);
	tmp = lst;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	display(t_list *list)
{
	t_list	*tmp;
	int	nbr = 0;

	tmp = list;
	while (tmp != NULL)
	{
		nbr = tmp->content;
		printf("|%d|->", nbr);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
