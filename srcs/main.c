/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:47:42 by galtange          #+#    #+#             */
/*   Updated: 2022/09/23 14:48:05 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

struct  node
{
    int info;
    struct node *next;
};
struct node *start=NULL;

void    display()
{
    struct node *ptr;
    if (start == NULL)
    {
        ft_putstr_fd("List is empty\n", 1);
        return;
    }
    else
    {
        ptr = start;
        ft_putstr_fd("The list elements are\n", 1);
        while (ptr != NULL)
        {
            printf("%d\n", ptr->info);
            ptr = ptr->next;
        }
    }
}

void	create(int nbrs)
{
	struct node	*temp;
	struct node	*ptr;

	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		ft_putstr_fd("Out of Memory Space\n", 1);
		exit(0);
	}
	temp->info = nbrs;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else
	{
		ptr = start;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}

void	insert_begin(int nbrs)
{
	struct node	*temp;

	temp = (struct node *)malloc(sizeof(struct node));
	if(temp == NULL)
	{
		ft_putstr_fd("Out of Memory Space\n", 1);
		return;
	}
	temp->info = nbrs;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else
	{
		temp->next = start;
		start = temp;
	}
}

void	insert_end(int nbrs)
{
	struct node	*temp;
	struct node	*ptr;
	
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		ft_putstr_fd("Out of Memory Space\n", 1);
		return;
	}
	temp->info = nbrs;
	temp->next = NULL;
	if (start == NULL)
		start = temp;
	else
	{
		ptr = start;
		while(ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = temp;
	}
}

void delete_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("nList is Empty:");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                printf("nThe deleted element is:%dt",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("nThe deleted element is:%dt",ptr->info);
                free(ptr);
        }
}

void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("nList is Empty:n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("nThe deleted element is :%dt",ptr->info);
                free(ptr);
        }
}

int main (int argc, char **argv)
{
	char	**all;
	int	*nbrs;
	int	i = 0;
	
	nbrs = NULL;
	if (argc != 1)
	{
		all = ft_split2(argc - 1, argv + 1);
		if (!all)
			return (write(1, "Error\n", 6));
		nbrs = ft_char2int(all, argc - 1);
		if (!nbrs || !ft_dupcheck(nbrs, argc - 1))
			return (write(1, "Error\n", 6));
		i = 0;
		while (i < (argc - 1))
			printf("|%d|\n", nbrs[i++]);
		ft_free(all, i);
	}
	printf("--display before push to stack ---\n");
	display();
	printf("\n---create test---\n");
	create(nbrs[0]);
	display();
	printf("\n---insert in begin test---\n");
	insert_begin(nbrs[1]);
	display();
	printf("\n--insert in end test---\n");
	insert_end(nbrs[2]);
	display();
	printf("\n--del in end---\n");
	delete_end();
	display();
	free(nbrs);
}

/* ver2
int main(int argc, char	**argv)
{
	char	*all;
	int		i = 0;
	char	**tmp;
	int	*nbrs;

	if (argc >= 1)
	{
		all = ft_joinall(argc - 1, argv + 1);
		if (!all)
		{
			free(all);i
			ft_putstr_fd("Error\n", 1);
		}
		tmp = ft_split(all, ' ');
		while (tmp[i])
		{	
			ft_putstr_fd(tmp[i++], 1);
			ft_putstr_fd("\n", 1);
		
		nbrs = (int *)malloc((i + 1) * sizeof(int));
		if (!nbrs)
			return (0);
		ft_char2int(tmp, nbrs);
		i = 0;
		while (nbrs[i])
			printf("%d\n", nbrs[i++]);
		free(all);
		ft_free(tmp, i);
		free(nbrs);

	}
	return (0);
}
*/
// int main(int argc, char **argv)
// {
// 	static int	tmp[10000];
// 	int		size;
// 	if (argc <= 1)
// 		return (0);
// 	/*while (argv[i])
// 	{
// 		tmp[valid] = ft_atoi(argv[i]);
// 		printf("%d\n", tmp[valid]);
// 		valid++;
// 		i++;
// 	}*/
// 	size = 0;
// 	printf("%d\n", argc);
// 	if ((size = ft_input(argv, &tmp[0])) == -1)
// 	{
// 		free(&tmp[0]);
// 		printf("Error\n");
// 		return (0);
// 	}
// 	ft_pushswap(&tmp[0], size);
// 	return (0);
// }