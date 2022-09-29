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

int	ft_size(char **nbrs)
{
	int	i;

	i = 0;
	while(*nbrs != NULL)
	{
		i++;
		nbrs++;
	}
	return (i);
}

int main (int argc, char **argv)
{
	char	**all;
	int	*nbrs;
	int	size = 0;
	
	nbrs = NULL;
	if (argc != 1)
	{
		all = ft_split2(argc - 1, argv + 1);
		if (!all)
			return (write(1, "Error\n", 6));
		nbrs = ft_char2int(all, size = ft_size(all));
		if (!nbrs || !ft_dupcheck(nbrs, size))
			return (write(1, "Error\n", 6));
		ft_free(all, size);
		push_swap(nbrs, size);
		free(nbrs);
	}
}
