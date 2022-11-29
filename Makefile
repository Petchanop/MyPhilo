# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:06:02 by npiya-is          #+#    #+#              #
#    Updated: 2022/11/29 16:09:43 by npiya-is         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C philo

bonus:
	make -C philo_bonus

clean:
	make -C philo clean
	make -C philo_bonus clean

fclean:
	make -C philo fclean
	make -C philo_bonus fclean

re:
	make -C philo re

rebonus:
	make -C philo_bonus re

.PHONY: all bonus clean fclean re rebonus