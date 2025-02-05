NAME = so_long

SRC = $(addprefix src/, main.c)

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LIBFT = -L ${LIBFT_PATH} -lft

all:	${NAME}

%.o: %.c
			@${CC} ${CFLAGS} ${INCLUDE} -o $@ -c $<

$(NAME): ${OBJS}
			@${MAKE} ${LIBFT_PATH} all
					@${CC} ${OBJS} ${LIBFT} -o ${NAME}

clean:
			@${MAKE} ${LIBFT_PATH} clean
					@${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
			@${MAKE} ${LIBFT_PATH} fclean
					@${RM} ${NAME} ${NAME}_bonus
					@echo "all clean"

re: fclean all

.PHONY: all clean fclean re
