/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:57:54 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/29 19:13:42 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHILOSOPHERS_BONUS_H
# define  PHILOSOPHERS_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <signal.h>
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
	sem_t			*fork;
	sem_t			*lock;
	sem_t			*print;
	sem_t			*eatall;
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
	pid_t			philo;
	pthread_t		th;
	int				time;
	int				die;
	int				id;
	int				fork;
	int				time_eat;
	int				time_not_eat;
	int				num_eat;
}	t_philo;

void	initialize_data(t_data *data, char **argv);
void	assign_data(t_philo *arg);
void	create_philo(t_data data, t_philo *th);
void	do_routines(t_data data, t_philo *philo);
void	*excute_routines(t_philo *philo, t_data data);
void	take_time(t_philo *philo, int ac, t_data data);
void	get_time(t_philo *philo, t_data data);
void	print_time(t_philo *philo, char *param, t_data data);
void	mysleep(int sleep);
void	eating(t_philo *philo, t_data data);
void	take_fork(t_philo *philo, t_data data);
void	sleeping(t_philo *philo, t_data data);
void	thinking(t_philo *philo, t_data data);
void	choose_fork(t_philo *philo, sem_t *mutex, t_data data);
void	drop_fork(t_philo *philo, sem_t *mutex);
void	buid_process(t_data data, t_philo *th);
void	check_philo(t_philo *philo, t_data data);
int		check_input(int argc, char **argv);
char	*assign_color(char *param);

#endif