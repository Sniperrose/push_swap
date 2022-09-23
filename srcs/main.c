/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:47:42 by galtange          #+#    #+#             */
/*   Updated: 2022/09/23 14:48:05 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main (int argc, char **argv)
{
	char	**all;
	int	*nbrs;
	int	i;
	
	if (argc >= 1)
	{
		all = ft_split2(argc - 1, argv + 1);
		if (!all)
			return (write(1, "Error\n", 6));
		nbrs = ft_char2int(all, argc - 1);
		if (!nbrs || !ft_dupcheck(nbrs, argc - 1))
			return (write(1, "Error\n", 6));
		i = 0;
		while (i < (argc - 1))
			printf("%d\n", nbrs[i++]);
		free(nbrs);
		ft_free(all, i);
	}
}

/* ver2
int main(int argc, char	**argv)
{
	char	*all;
	int		i = 0;
	char	**tmp;
	int	*nbrs;

	if (argc >= 1)
	{
		all = ft_joinall(argc - 1, argv + 1);
		if (!all)
		{
			free(all);i
			ft_putstr_fd("Error\n", 1);
		}
		tmp = ft_split(all, ' ');
		while (tmp[i])
		{	
			ft_putstr_fd(tmp[i++], 1);
			ft_putstr_fd("\n", 1);
		
		nbrs = (int *)malloc((i + 1) * sizeof(int));
		if (!nbrs)
			return (0);
		ft_char2int(tmp, nbrs);
		i = 0;
		while (nbrs[i])
			printf("%d\n", nbrs[i++]);
		free(all);
		ft_free(tmp, i);
		free(nbrs);

	}
	return (0);
}
*/
// int main(int argc, char **argv)
// {
// 	static int	tmp[10000];
// 	int		size;
// 	if (argc <= 1)
// 		return (0);
// 	/*while (argv[i])
// 	{
// 		tmp[valid] = ft_atoi(argv[i]);
// 		printf("%d\n", tmp[valid]);
// 		valid++;
// 		i++;
// 	}*/
// 	size = 0;
// 	printf("%d\n", argc);
// 	if ((size = ft_input(argv, &tmp[0])) == -1)
// 	{
// 		free(&tmp[0]);
// 		printf("Error\n");
// 		return (0);
// 	}
// 	ft_pushswap(&tmp[0], size);
// 	return (0);
// }
