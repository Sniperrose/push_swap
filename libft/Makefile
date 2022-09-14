SRCS = ft_isdigit.c\
       ft_strlen.c\
       ft_substr.c\
       ft_strjoin.c\
       ft_split.c\
       ft_putchar_fd.c\
       ft_putstr_fd.c

OBJS = ${SRCS:.c=.o}

HEADER = libft.h

NAME = libft.a

CC = clang

RM = rm -f

FLAGS = -Wall -Werror -Wextra

%.o:	%.c ${HEADER}
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
