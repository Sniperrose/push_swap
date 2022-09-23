/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:50:17 by galtange          #+#    #+#             */
/*   Updated: 2022/09/23 14:50:22 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*ft_char2int(char **tmp, int size)
{
	int			i;
	int			*nbrs;
	long long	nb;	

	i = 0;
	nb = 0;
	nbrs = (int *)malloc(size * sizeof(int));
	if (!nbrs || !tmp)
		return (NULL);
	while (tmp[i] && i < size)
	{
		nb = ft_atoi2(tmp[i]);
		if (nb > 2147483647 || nb < -2147483648)
		{
			free(nbrs);
			return (NULL);
		}
		nbrs[i] = (int)nb;
		i++;
	}
	return (nbrs);
}

int	ft_stralpha(char *s)
{
	int		i;

	i = 0;
	while ((s[i] > 7 && s[i] < 14) || (s[i] == 32))
		i++;
	while (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_dupcheck(int *nbrs, int size)
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**ft_split2(int size, char **nbrs)
{
	char	**result;
	int		line;

	result = (char **)malloc((size + 1) * sizeof(char *));
	if (!nbrs || !result)
		return (NULL);
	line = 0;
	while (line < size)
	{
		result[line] = ft_substr(nbrs[line], 0, ft_strlen(nbrs[line]));
		if (!result[line] || ft_stralpha(result[line]))
		{
			ft_free(result, line);
			return (NULL);
		}
		line++;
	}
	result[line] = NULL;
	return (result);
}

void	ft_free(char **ptr, size_t line)
{
	while (0 < line)
	{
		free(ptr[line]);
		line--;
	}
	free(ptr);
}
