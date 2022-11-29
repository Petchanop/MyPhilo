/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:22:46 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/29 20:35:11 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILOSOPHERS_H
# define  PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "../../utils/utils.h"

# define RED "\x1b[31m"
# define BLUE "\x1b[34m"
# define GREEN "\x1b[32m"
# define WHITE "\x1b[37m"
# define CYAN "\x1b[36m"
# define MAGENTA "\x1b[35m"
# define REDBG "\x1b[41m"
# define BLUEBG "\x1b[44m"
# define GREENBG "\x1b[42m"
# define WHITEBG "\x1b[47m"
# define CYANBG "\x1b[46m"
# define MAGENTABG "\x1b[45m"

typedef struct s_data
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	pthread_mutex_t	print;
	int				eat;
	int				die;
	int				num_fork;
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	struct timeval	begin;
}	t_data;

typedef struct s_philo
{
	pthread_t		philo;
	t_data			*data;
	unsigned long	time;
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
void	take_fork(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	choose_fork(t_philo *philo, pthread_mutex_t *mutex);
void	drop_fork(t_philo *philo, pthread_mutex_t *mutex);
int		check_philo(t_philo *philo);
int		check_input(int argc, char **argv);
char	*assign_color(char *param);

#endif