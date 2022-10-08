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

int	g_cntr;

int	main(int argc, char **argv)
{
	int *result;
	int size;
    int i;

	g_cntr = 0;
	size = 0;
	result = NULL;
	if (argc <= 1)
		return (0);
	else
		result = ft_joinall(argv + 1, &size);
	// ft_pushswap(&result[0], size);
	i = 0;
	while (i < size)
		printf("%d", result[i++]);
	free(result);
	return (0);
}
