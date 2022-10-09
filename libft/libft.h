/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galtange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:46:22 by galtange          #+#    #+#             */
/*   Updated: 2022/01/05 18:46:29 by galtange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		ft_isalpha(char c);
int		ft_isdigit(char c);
size_t	ft_strlen(const char *c);
char    *ft_strdup(char const *argv);
char    *ft_strjoin(char *all, char const *argv);
void	ft_split(char **result, char const *all, char sep, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
