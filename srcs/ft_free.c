#include "../include/push_swap.h"

void	ft_free(void *tmp)
{
	int i = 0;
	
	while (tmp)
	{
		free(tmp[i]);
		i++;
	}

}
