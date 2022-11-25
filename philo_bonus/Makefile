# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 21:27:14 by npiya-is          #+#    #+#              #
#    Updated: 2022/11/25 14:43:54 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

THREAD = -lpthread 

SRCS_DIR= srcs_bonus/
UTILS_DIR= utils/

SRCS= $(SRCS_DIR)philo_bonus.c \
	$(SRCS_DIR)create_thread_bonus.c \
	$(SRCS_DIR)routines_bonus.c \
	$(SRCS_DIR)assign_data_bonus.c \
	$(SRCS_DIR)life_bonus.c \
	$(SRCS_DIR)print_time_bonus.c \
	$(SRCS_DIR)do_routines_bonus.c \

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