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
	int result[10000];
	int size;
    int i;

	g_cntr = 0;
	i = 0;
	size = 0;
	if (argc <= 1)
		return (0);
	else
		ft_joinall(argv + 1, &result[0], &size);
	// while(i < size)
	// 	printf("%d\n", result[i++]);
	ft_pushswap(&result[0], size);
	printf("cntr is : %d\n", g_cntr);
	return (0);
}
