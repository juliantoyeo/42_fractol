# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyeo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 14:15:58 by jyeo              #+#    #+#              #
#    Updated: 2018/01/25 00:00:51 by jyeo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAG = -Wall -Wextra -Werror

CC = gcc

SRC =       		srcs/draw_fractol.c\
					srcs/julia.c\
					srcs/key_hook.c\
					srcs/main.c\
					srcs/mandelbrot.c\
					srcs/mouse_hook.c\
					srcs/mouse_move.c\
					srcs/option.c\
					srcs/ship.c\
					srcs/utils.c\
					srcs/zoom.c\

INCLUDES = -I includes

OBJ = $(SRC:.c=.o)
LIBS = -L libft/ -lft
MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx
OPENGL = -framework OpenGL -framework Appkit

all: lib $(NAME)

lib:
	@make -C libft/

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBS) $(MLX) $(OPENGL)

$(OBJ): %.o: %.c Makefile includes/fractol.h
	$(CC) $(FLAG) $(INCLUDES) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	make clean -C libft/

fclean:	clean
	@/bin/rm -f $(NAME)
	make fclean -C libft/

re:	fclean all
