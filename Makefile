# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpatrici <jpatrici@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 15:56:46 by jpatrici          #+#    #+#              #
#    Updated: 2025/02/13 16:05:30 by jpatrici         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = $(addprefix src/, main.c floodfill.c parsing.c keyhooks.c)

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
MLXFLAGS = -L -lm -Ilmlx -lXext -lX11
INCLUDE = -I include
MAKE = make -C
LIBFT_PATH = libft
LIBFT = ${LIBFT_PATH}/libft.a

MLX_PATH = minilibx-linux
MLX = ${MLX_PATH}/libmlx.a
all:	${NAME}

deps:
	@${MAKE} ${LIBFT_PATH} all
	@${MAKE} ${MLX_PATH}

	
$(NAME): deps ${OBJS}
	${CC} ${OBJS} ${LIBFT} ${MLXFLAGS} ${MLX} -o ${NAME}

clean:
	${MAKE} ${LIBFT_PATH} clean
	${RM} ${OBJS}

fclean: clean
	${MAKE} ${LIBFT_PATH} fclean
	${RM} ${NAME} 
	echo "all clean"

re: fclean all

.PHONY: all clean fclean re
