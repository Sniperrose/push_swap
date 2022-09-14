#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv);
int	ft_input(char **argv, int *tmp);
long int	ft_atoi(char *nptr);
void	ft_pushswap(int *stack, int i);
void	ft_free(void *tmp);
#endif
