/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
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
	printf ("Error\n");
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

void	ft_joinall(char **argv, int *nbrs, int *size)
{
	long long	nb;
	int			i;
	int			line;

	i = 0;
	line = 0;
	if (!argv || !*argv)
		return ;
	while (argv[i])
	{
		if (ft_isalpha(argv[i][0]))
			ft_error(nbrs, line);
		nb = ft_atoi2(argv[i]);
		if (nb > 2147483647 || nb < -2147483648)
			ft_error(nbrs, line);
		nbrs[line] = (int)nb;
		i++;
		line++;
	}
	*size = line;
	if (ft_duplicated(nbrs, line))
		ft_error(nbrs, line);
}
