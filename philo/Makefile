# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 01:28:49 by npiya-is          #+#    #+#              #
#    Updated: 2022/11/21 14:25:57 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

THREAD = -lpthread

SRCS_DIR= srcs/
UTILS_DIR= utils/

SRCS= $(SRCS_DIR)main_philosophers.c \
	$(SRCS_DIR)create_thread.c \
	$(SRCS_DIR)routines.c \
	$(SRCS_DIR)assign_data.c \
	$(SRCS_DIR)life.c \
	$(SRCS_DIR)print_time.c \
	$(SRCS_DIR)do_routines.c \

NAME= philo

LIB= -lftprintf
LIB_DIR= -L ../include/ft_printf

all: $(NAME)

$(NAME):
	@make -C ../include/ft_printf
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(LIB_DIR) $(LIB) $(THREAD)

fclean:
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all

