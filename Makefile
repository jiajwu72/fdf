#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwu <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/27 17:41:28 by jwu               #+#    #+#              #
#    Updated: 2018/01/17 19:24:06 by jwu              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = fdf.h

SRC =	fdf_draw.c fdf_get_info.c fdf_hook.c fdf_init_map.c fdf_is_correct.c \
	 fdf_gere_color.c fdf_absolue.c fdf_calculf.c main.c fdf_drawline.c fdf_free.c\

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
