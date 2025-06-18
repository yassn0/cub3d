# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yfradj <yfradj@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 07:23:33 by yfradj            #+#    #+#              #
#    Updated: 2025/06/18 07:34:51 by yfradj           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Werror -Wextra -lm
FLAGS_X = -lXext -lX11

WAY = srcs/

LIB_USE = libft/libft.a minilibx-linux/libmlx.a

SRCS = \
	$(WAY)main.c \

OBJS = $(SRCS:.c=.o)
	
NAME = cub3d
	

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft --no-print-directory
	@make -C minilibx-linux --no-print-directory
	$(CC) $(FLAGS) $(FLAGS_X) $(OBJS) $(LIB_USE) -o $(NAME)
	
clean:
	@make clean -C libft --no-print-directory
	@rm -f $(OBJS) 

fclean: clean
	@make fclean -C libft --no-print-directory
	@make clean -C minilibx-linux --no-print-directory
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all fclean clean bonus re