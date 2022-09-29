#include "../include/push_swap.h"

void	ft_pushswap(int	*nbrs, int size)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int	i;

	stack_a = NULL;
	stack_b = NULL;
	i = size - 1;
	while (i >= 0)
	{
		ft_lstadd_front(&stack_a, ft_lstnew(nbrs[i--]));
	}
	display(stack_a);
	printf("---after sa---\n size = %d\n", ft_lstsize(stack_a));
	ft_sa(&stack_a);
	display(stack_a);
	printf("---after sb---\n");
	ft_sb(&stack_b);
	display(stack_b);
	ft_ss(&stack_a, &stack_b);
	printf("---ss--\n");
	display(stack_a);
	display(stack_b);
	printf("---pb---\n");
	ft_pb(&stack_a, &stack_b);
	display(stack_a);
	display(stack_b);
	printf("---pa---\n");
	ft_pa(&stack_a, &stack_b);
	display(stack_a);
	display(stack_b);
	printf("---rotate---\n");
	ft_rotate(&stack_a);
	display(stack_a);
	printf("---reverse---\n");
	ft_reverse(&stack_a);
	display(stack_a);
}

char	**ft_strjoinall(char **nbrs)
{
	char	*all;
	char	**result;
	int	i;

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
	if (!(result = ft_split(all, ' ')))
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

int main (int argc, char **argv)
{
	char		**result;
	int	*nbrs;
	int	size;

	nbrs = NULL;
	result = NULL;
	if (argc > 1)
	{
		if (!(result = ft_strjoinall(argv + 1)))
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
		free(nbrs);
		ft_free(result, size);
	}
	return (0);
}
