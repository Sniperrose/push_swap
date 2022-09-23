/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:59:55 by galtange          #+#    #+#             */
/*   Updated: 2022/09/23 15:00:10 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long long	ft_atoi2(const char *nptr)
{
	int			i;
	int			sign;
	long long	num;

	i = 0;
	num = 0;
	sign = 1;
	while ((nptr[i] > 7 && nptr[i] < 14) || (nptr[i] == 32))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		num = 10 * num + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}
