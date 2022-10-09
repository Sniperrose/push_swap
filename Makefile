NAME = push_swap

SRCS =	srcs/main.c\
		srcs/ft_atoi2.c\
		srcs/ft_joinall.c\
		srcs/ft_getnbrs.c\
		srcs/push_swap.c\
		srcs/ft_median.c\
		srcs/ft_push.c\
		srcs/ft_revrotate.c\
		srcs/ft_rotate.c\
		srcs/ft_sort_small.c\
		srcs/ft_sort_mid.c\
		srcs/ft_sort_big.c\
		srcs/ft_stacks.c\
		srcs/ft_swap.c\
		srcs/ft_minmax.c

INCLUDE = includes

OBJS = ${SRCS:.c=.o}

CC = clang

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -I $(INCLUDE) -c $< -o $@

$(NAME): ${OBJS}
		make -C libft/
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) libft/libft.a -o $(NAME)

all: ${NAME}

clean:
	make clean -C libft/
	${RM} $(OBJS)

fclean:	clean
	${RM} ${NAME}
	make fclean -C libft/

re:	fclean all
