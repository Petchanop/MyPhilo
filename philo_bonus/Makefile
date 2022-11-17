# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 21:27:14 by npiya-is          #+#    #+#              #
#    Updated: 2022/11/15 21:55:36 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

THREAD = -lpthread 

SRCS_DIR= srcs/
UTILS_DIR= utils/

SRCS= philo_bonus.c \
	create_thread_bonus.c \
	routines_bonus.c \
	assign_data_bonus.c \
	life_bonus.c \
	print_time_bonus.c \
	do_routines_bonus.c \

NAME= philo_bonus

LIB= -lftprintf
LIB_DIR= -L ../include/ft_printf

all: $(NAME)

$(NAME):
	@make -C ../include/ft_printf
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIB_DIR) $(LIB) $(THREAD)

fclean:
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all