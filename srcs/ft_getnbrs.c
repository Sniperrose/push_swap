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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (!s1)
		str = malloc((ft_strlen(s2) + 1) * sizeof(char));
	else
		str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	len = 0;
	while (s2[len] != '\0')
	{
		str[i + len] = s2[len];
		len++;
	}
	str[i + len] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	*ft_joinall(char **argv, int *size)
{
	char	*all;
	int		*nbrs = NULL;
	int		i = 0;

	if (!argv || !*argv)
		return (NULL);
	all = ft_strdup(argv[i]);
	if (!all)
		return (NULL);
	i++;
	while (argv[i])
	{
		all = ft_strjoin(all, argv[i]);
		i++;
	}
	nbrs[0] = ft_atoi2(all);
	*size = i;
	free (all);
	return(&nbrs[0]);
}
