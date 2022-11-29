# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 01:28:49 by npiya-is          #+#    #+#              #
#    Updated: 2022/11/29 16:18:00 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

THREAD = -lpthread

SRCS_DIR= srcs/
UTILS_DIR= ../utils/

SRCS= $(SRCS_DIR)main_philosophers.c \
	$(SRCS_DIR)create_thread.c \
	$(SRCS_DIR)routines.c \
	$(SRCS_DIR)assign_data.c \
	$(SRCS_DIR)life.c \
	$(SRCS_DIR)print_time.c \
	$(SRCS_DIR)do_routines.c \

SRCS_UTILS= $(UTILS_DIR)ft_atoi.c \
	$(UTILS_DIR)ft_isalpha.c \
	$(UTILS_DIR)ft_isdigit.c \
	$(UTILS_DIR)ft_strlen.c \

OBJS=$(SRCS:%.c=%.o)

OBJS_UTILS=$(SRCS_UTILS:%.c=%.o)

NAME= philo

all: $(NAME)

$(NAME):$(OBJS) $(OBJS_UTILS)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_UTILS) -o $(NAME) $(THREAD)

clean:
	rm -rf $(OBJS)
	rm -rf ../utils/$(OBJS_UTILS)

fclean:clean
	rm -rf $(NAME) $(NAME).dSYM

re: fclean all

.PHONY: re fclean clean all