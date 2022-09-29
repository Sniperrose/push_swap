/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:49:40 by galtange          #+#    #+#             */
/*   Updated: 2022/09/23 14:49:46 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	substr = malloc ((len + 1) * sizeof(char));
	if (!s || !substr)
		return (NULL);
	while (i < len && s)
	{
		substr[i++] = s[start++];
	}
	substr[i] = '\0';
	return (substr);
}

char	**ft_strjoinall(char **nbrs)
{
	char	*all;
	char	**result;
	int		i;

	i = 0;
	all = ft_substr(nbrs[i], 0, ft_strlen(nbrs[i]));
	if (!all || !ft_stralpha(all))
		return (NULL);
	i++;
	while (nbrs[i])
	{
		all = ft_strjoin(all, nbrs[i]);
		if (!all)
			return (NULL);
		i++;
	}
	result = ft_split(all, ' ');
	if (!result)
	{
		free(all);
		return (NULL);
	}
	free(all);
	return (result);
}

int	line(char **result)
{
	int	size;

	size = 0;
	while (result[size])
		size++;
	return (size);
}
