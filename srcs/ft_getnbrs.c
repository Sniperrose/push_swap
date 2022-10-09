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

void	ft_error(char **str, int *nbr)
{
	ft_free(str, ft_splitsize(str));
	free(nbr);
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

size_t	ft_splitsize(char **str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != NULL)
			i++;
	return (i);
}

void	ft_char2int(char **result, int *nbrs, int *size)
{
	long long	nb;
	int			i;
	int			line;

	if (!result || !*result)
		return ;
	i = 0;
	line = 0;
	while(result[i] != NULL)
	{
		if (ft_isalpha(result[i][0]))
			ft_error(result, nbrs);
		nb = ft_atoi2(result[i]);
		if (nb > 2147483647 || nb < -2147483648)
			ft_error(result, nbrs);
		nbrs[line] = (int)nb;
		i++;
		line++;
	}
	*size = line;
	if (ft_duplicated(nbrs, line))
		ft_error(result, nbrs);
}

int	*ft_getnumbers(char *all, int *size)
{
	size_t	i;
	int		*nbrs;
	char	**result;

	if (!all)
		return (0);
	result = (char **)malloc((ft_count(all, ' ') + 1) * sizeof(char *));
	if (!result)
		return (0);
	ft_split(result, all, ' ', ft_count(all, ' ') + 1);
	if (!result)
		return (0);
	i = ft_splitsize(result);
	nbrs = malloc(i * sizeof(int));
	if (!nbrs)
	{
		ft_free(result, i);
		return (0);
	}
	ft_char2int(result, nbrs, size);
	if (!nbrs)
	{
		ft_free(result, i);
		return (NULL);
	}
	ft_free(result, i);
	return (nbrs);
}
