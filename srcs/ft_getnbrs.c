/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 20:07:08 by galtange          #+#    #+#             */
/*   Updated: 2021/12/07 20:07:34 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(int *nbr, int i)
{
	while (--i >= 0)
		nbr[i] = 0;
	printf ("error\n");
	exit(0);
}

int	ft_duplicated(int *nbrs, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nbrs[i] == nbrs[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	ft_count(const char *all, char sep)
{
	int		i;
	size_t	line;
	
	if (!all)
		return (0);
	i = 0;
	line = 0;
	while (*all != '\0' && *all == sep)
		all++;
	while (*all != '\0')
	{
		if (*all != sep && i == 0)
		{
			line++;
			i = 1;
		}
		if (i == 1 && *all == sep)
			i = 0;
		all++;
	}
	return (line);
}


size_t	ft_getnumbers(const char *all)
{
	// size_t	size;
	// size_t	i;
	size_t	ch;

	if (!all)
		return (0);
	result = NULL;
	ch = ft_count(all, ' ');

	return (ch);
}