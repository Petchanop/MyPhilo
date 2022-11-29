# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 21:27:14 by npiya-is          #+#    #+#              #
#    Updated: 2022/11/29 16:17:55 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra

THREAD = -lpthread 

SRCS_DIR= srcs_bonus/
UTILS_DIR= ../utils/

SRCS= $(SRCS_DIR)philo_bonus.c \
	$(SRCS_DIR)create_thread_bonus.c \
	$(SRCS_DIR)routines_bonus.c \
	$(SRCS_DIR)assign_data_bonus.c \
	$(SRCS_DIR)life_bonus.c \
	$(SRCS_DIR)print_time_bonus.c \
	$(SRCS_DIR)do_routines_bonus.c \

SRCS_UTILS= $(UTILS_DIR)ft_atoi.c \
	$(UTILS_DIR)ft_isalpha.c \
	$(UTILS_DIR)ft_isdigit.c \
	$(UTILS_DIR)ft_strlen.c \

OBJS=$(SRCS:%.c=%.o)

OBJS_UTILS=$(SRCS_UTILS:%.c=%.o)

NAME= philo_bonus

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