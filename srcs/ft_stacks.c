/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 20:33:17 by galtange          #+#    #+#             */
/*   Updated: 2022/10/08 12:50:28 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (0);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

int	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return (1);
	}
	if (!new)
		return (0);
	new->next = *lst;
	*lst = new;
	return (1);
}

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 0;
	if (!lst)
		return (0);
	tmp = lst;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	free_stack(t_list **list)
{
	t_list	*tmp;

	if (!*list || !list)
	{
		return ;
	}
	while (*list != NULL)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
}

void	display(t_list *list)
{
	t_list	*tmp;
	int		nbr;

	nbr = 0;
	tmp = list;
	while (tmp != NULL)
	{
		nbr = tmp->content;
		printf("%d ", nbr);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

