#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *c);
void	ft_putstr_fd(char *s, int fd);
long long	ft_atoi2(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	*ft_char2int(char **tmp, int size);
int	ft_stralpha(char *str);
int	ft_dupcheck(int *nbrs, int size);
char	**ft_split2(int	size, char **nbrs);
void	ft_free(char **ptr, size_t line);

#endif
