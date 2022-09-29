#include "../include/push_swap.h"

void    ft_revrotate(t_list **list)
{
    t_list  *tmp;
    t_list  *other;

    if (!list || !*list || (ft_lstsize(*list) < 2))
        return ;
    other = *list;
    while (other->next->next != NULL)
        other = other->next;
    tmp = *list;
    other->next = NULL;
    tmp->next = other;
}