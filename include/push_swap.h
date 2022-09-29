#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_list
{
	int		content;
	struct s_list	*next;
}	t_list;


size_t	ft_strlen(const char *c);
void	ft_putstr_fd(char *s, int fd);
long long	ft_atoi2(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	*ft_char2int(char **tmp, int size);
int	ft_stralpha(char *str);
int	ft_dupcheck(int *nbrs, int size);
char	**ft_split(char const *s, char c);
char	**ft_split2(int size, char **nbrs);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **ptr, size_t line);
void    push_swap(int *nbrs, int size);
void    display(t_list *list);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
void	ft_sa(t_list **list);
void	ft_sb(t_list **list);
void	ft_push(t_list **st1, t_list **st2);
void	ft_rotate(t_list **list);
void	ft_reverse(t_list **list);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_stacktest(int *nbrs, int size);

#endif
