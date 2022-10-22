# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 01:28:49 by npiya-is          #+#    #+#              #
#    Updated: 2022/10/22 21:55:25 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

THREAD = -pthread

SRCS_DIR= srcs/
UTILS_DIR= utils/

SRCS= main_philosophers.c \
	create_thread.c \
	routines.c \
	assign_data.c \
	life.c

NAME= philo

LIB= -lftprintf
LIB_DIR= -L include/ft_printf

all: $(NAME)

$(NAME):
	@make -C include/ft_printf
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIB_DIR) $(LIB)

fclean:
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all

