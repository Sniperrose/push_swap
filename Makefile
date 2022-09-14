NAME = push_swap

SRCS = srcs/main.c\
       srcs/ft_input.c\
       srcs/ft_pushswap.c

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
