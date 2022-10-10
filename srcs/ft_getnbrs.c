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

int	 ft_char2int(char **result, int *nbrs)
{
	long long	nb;
	int			i;
	int			line;

	if (!result || !*result)
		return (0);
	i = 0;
	line = 0;
	while(result[i] != NULL)
	{
		if (ft_isalpha(result[i][0]))
		{	
			write (1, "Error momomo\n", 6);
			return (0);
		}
		nb = ft_atoi2(result[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			write (1, "Error lalalal\n", 6);
			return (0);
		}
		nbrs[line] = (int)nb;
		i++;
		line++;
	}
	if (ft_duplicated(nbrs, line))
	{
		write (1, "Error dududud\n", 6);
		return (0);
	}
	return (line);
}

int	*ft_getnumbers(char *all, int *size)
{
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
	nbrs = malloc(ft_splitsize(result) * sizeof(int));
	if (!nbrs)
	{
		ft_free(result, ft_splitsize(result));
		return (NULL);
	}
	*size = ft_char2int(result, nbrs);
	if (!nbrs || !size)
	{
		ft_free(result, ft_splitsize(result));
		return (NULL);
	}
	ft_free(result, ft_splitsize(result));
	return (nbrs);
}
