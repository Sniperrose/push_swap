#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

extern int g_cntr;

typedef struct	s_list
{
	int		content;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(const char *c);
int	ft_isalpha(char c);
long long	ft_atoi2(const char *nptr);
char    *ft_joinall(char *str, char const *argv);
char    *ft_strjoin(char *all, char const *argv);
char    *ft_strdup(char const *argv);



int	ft_duplicated(int *nbrs, int size);
size_t	ft_splitsize(char **str);
void	ft_free(char **str, size_t line);

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
size_t	ft_count(const char *all, char sep);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_split(char **result, char const *all, char sep, size_t size);

int	*ft_getnumbers(char *all, int *size);

void	ft_pushswap(int	*nbrs, int size);
void    display(t_list *list);
t_list	*ft_lstnew(int content);
t_list	*ft_newstack(int *nbrs, int size);
int	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
void	free_stack(t_list **list);
void    ft_swap(t_list **list);
void    ft_sa(t_list **stack_a);
void    ft_sb(t_list **stack_b);
void    ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_push(t_list **st1, t_list **st2);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_rotate(t_list **list);
void    ft_ra(t_list **stack_a);
void    ft_rb(t_list **stack_b);
void    ft_rr(t_list **stack_a, t_list **stack_b);
void    ft_revrotate(t_list **list);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);
void ft_swap_nbr(int *a, int *b);
int	*ft_sort_nbrs(int *tmp, int size);
int	ft_median(t_list **stack, int size);
int	ft_alreadysorted(t_list **stack);
void	ft_sort_3(t_list **stack);
void	ft_sort_4(t_list **stack_a, t_list **stack_b, int med);
void	ft_sort_5(t_list **stack_a, t_list **stack_b, int med);
void	ft_sort(t_list **stack_a, t_list **stack_b, int med);
int     ft_minmax(t_list **sb, int *flag_ra, int *flag_rrb);
void	ft_sort_big(t_list **stack_a, t_list **stack_b);

#endif
