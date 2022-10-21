/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:22:46 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/21 23:05:22 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILOSOPHERS_H
# define  PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "include/ft_printf/srcs/ft_printf.h"

typedef struct s_data
{
	int	num_fork;
	int	num_philo;
	int	*fork;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;	
}	t_data;

typedef struct s_philo
{
	pthread_t		philo;
	pthread_mutex_t	lock;
	int				id;
	int				fork;
	int				die;
	int				eat;
	int				sleep;
	int				num_eat;
}	t_philo;

void	initialize_data(t_data *data, char **argv);
void	take_fork(t_data *data, t_philo *philo);
void	*assign_data(void *arg);
void	create_philo(t_data data, t_philo *th);
void	do_routines(t_data data, t_philo *philo);
void	*excute_routines(t_data data, t_philo *philo);

#endif