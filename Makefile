SRCS = push_swap.c parsing.c utils.c utils2.c instructions.c instructions2.c double.c algo.c utils3.c
OBJS = ${SRCS:.c=.o}
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT = ./libft
INCLUDES = -I/usr/include -Imlx -Iincludes

all : ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./libft/
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./libft/libft.a ${MLX_FLAGS}

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	${MAKE} clean -C ./libft/
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
