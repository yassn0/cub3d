# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 07:23:33 by yfradj            #+#    #+#              #
#    Updated: 2025/07/05 07:54:28 by yfradj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -g3 -Wall -Werror -Wextra -lXext -lX11 -lm -lz

WAY = srcs/
WAY2 = srcs/parsing/
WAY3 = srcs/raycasting/

LIB_USE = libft/libft.a

SRCS = \
	$(WAY)main.c \
	$(WAY)windows.c \
	$(WAY)utils.c \
	$(WAY)free.c \
	$(WAY2)parsing.c \
	$(WAY2)check.c \
	$(WAY2)check_utils.c \
	$(WAY2)get_data.c \
	$(WAY3)init.c \
	$(WAY3)raycasting.c \
	$(WAY3)render.c \
	$(WAY3)player.c \
	$(WAY3)texture.c \

OBJS = $(SRCS:.c=.o)
	
NAME = cub3D
	

all: $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -g3 -Wall -Werror -Wextra -c $< -o $@
	
$(NAME): $(OBJS)
	@make -C libft --no-print-directory
	@make -C mlx_linux --no-print-directory
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux $(FLAGS) $(LIB_USE) -o $(NAME)
	
clean:
	@make clean -C libft --no-print-directory
	@rm -f $(OBJS) 

fclean: clean
	@make fclean -C libft --no-print-directory
	@make clean -C mlx_linux --no-print-directory
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all fclean clean bonus re