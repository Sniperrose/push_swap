#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *c);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_joinall(int count, char **str);
int	ft_size(int	count, char **str);
char	**ft_split(char const *s, char c);
void	ft_free(char **ptr, size_t line);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
