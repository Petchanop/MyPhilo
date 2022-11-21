/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:22:46 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/21 14:26:19 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILOSOPHERS_H
# define  PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "../../include/ft_printf/srcs/ft_printf.h"

# define RED "\x1b[31m"
# define BLUE "\x1b[34m"
# define GREEN "\x1b[32m"
# define WHITE "\x1b[37m"
# define CYAN "\x1b[36m"
# define MAGENTA "\x1b[35m"

typedef struct s_data
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	int				eat;
	int				die;
	int				num_fork;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	struct timeval	begin;
	int				time;
}	t_data;

typedef struct s_philo
{
	pthread_t		philo;
	t_data			*data;
	int				die;
	int				id;
	int				fork;
	int				time_eat;
	int				time_not_eat;
	int				num_eat;
}	t_philo;

void	initialize_data(t_data *data, char **argv);
void	assign_data(t_data *data, t_philo *arg);
void	create_philo(t_data data, t_philo *th);
void	do_routines(t_data *data, t_philo *philo);
void	*excute_routines(void *arg);
void	take_time(t_philo *philo, int ac);
void	get_time(t_philo *philo);
void	print_time(t_philo *philo, char *param);
void	mysleep(int sleep);
void	eating(t_philo *philo);
void	do_others(t_philo *philo);
void	take_fork(t_philo *philo);
int		check_philo(t_philo *philo);
char	*assign_color(char *param);

#endif