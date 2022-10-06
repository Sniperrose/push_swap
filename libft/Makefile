# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galtange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 18:36:12 by galtange          #+#    #+#              #
#    Updated: 2022/01/04 20:53:42 by galtange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c\
       ft_isdigit.c\
       ft_strlen.c\
       ft_putchar_fd.c\
       ft_putstr_fd.c\

OBJS = ${SRCS:.c=.o}

HEADER = libft.h

NAME = libft.a

CC = clang

RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o:	%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}
			
clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re