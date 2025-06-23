# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 07:23:33 by yfradj            #+#    #+#              #
#    Updated: 2025/06/23 12:58:16 by yfradj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra -lXext -lX11 -lm -lz

FLAGS_TMP = -g3 -lXext -lX11 -lm -lz

WAY = srcs/
WAY2 = srcs/parsing/

LIB_USE = libft/libft.a

SRCS = \
	$(WAY)main.c \
	$(WAY)debug.c \
	$(WAY2)parsing.c \

OBJS = $(SRCS:.c=.o)
	
NAME = cub3d
	

all: $(NAME)

%.o: %.c
	$(CC) -g -I/usr/include -Imlx_linux -c $< -o $@
	# $(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@
	
$(NAME): $(OBJS)
	@make -C libft --no-print-directory
	@make -C mlx_linux --no-print-directory
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux $(FLAGS_TMP) $(LIB_USE) -o $(NAME)
	
clean:
	@make clean -C libft --no-print-directory
	@rm -f $(OBJS) 

fclean: clean
	@make fclean -C libft --no-print-directory
	@make clean -C mlx_linux --no-print-directory
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all fclean clean bonus re