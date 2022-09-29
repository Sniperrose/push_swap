/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:00:25 by galtange          #+#    #+#             */
/*   Updated: 2022/09/29 18:00:32 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char	**result;
	int		*nbrs;
	int		size;

	nbrs = NULL;
	result = NULL;
	if (argc > 1)
	{
		result = ft_strjoinall(argv + 1);
		if (!result)
		{
			ft_putstr_fd("error_str\n", 1);
			return (0);
		}
		nbrs = ft_char2int(&result[0], size = line(result));
		if (!size || !ft_dupcheck(nbrs, size) || !nbrs)
		{
			printf("error in size\n");
			return (0);
		}
		ft_pushswap(nbrs, size);
		ft_free(result, size);
		free(nbrs);
	}
	return (0);
}
