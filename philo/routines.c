/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:43:29 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/22 21:41:01 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(void *arg)
{
	int				fork;
	t_philo			*philo;
	struct timeval	end;
	int				time_sec;
	int				time_usec;

	philo = (t_philo *)arg;
	fork = philo->data.num_fork;
	pthread_mutex_lock(&philo->data.fork[philo->id - 1]);
	gettimeofday(&end, NULL);
	time_sec = (end.tv_sec - philo->data.begin.tv_sec) * 1000;
	time_usec = (end.tv_usec - philo->data.begin.tv_usec) / 1000;
	philo->data.time = time_sec + time_usec;
	pthread_mutex_lock(&philo->data.fork[philo->id % fork]);
	philo->fork++;
	printf("%d ms ", philo->data.time);
	printf("%d has taken a fork\n", philo->id);
	gettimeofday(&end, NULL);
	time_sec = (end.tv_sec - philo->data.begin.tv_sec) * 1000;
	time_usec = (end.tv_usec - philo->data.begin.tv_usec) / 1000;
	philo->data.time = time_sec + time_usec;
	philo->fork++;
	printf("%d ms ", philo->data.time);
	printf("%d has taken a fork\n", philo->id);
	eating(philo);
	pthread_mutex_unlock(&philo->data.fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->data.fork[philo->id % fork]);
}

void	eating(t_philo *philo)
{
	struct timeval	end;
	int				time_sec;
	int				time_usec;

	if (philo->fork == 2)
	{
		usleep(philo->data.time_to_eat * 1000);
		gettimeofday(&end, NULL);
		time_sec = (end.tv_sec - philo->data.begin.tv_sec) * 1000;
		time_usec = (end.tv_usec - philo->data.begin.tv_usec) / 1000;
		philo->data.time = time_sec + time_usec;
		printf("%d ms ", philo->data.time);
		printf("%d is eating\n", philo->id);
		philo->fork = 0;
	}
}

void	sleeping(t_philo *philo)
{
	struct timeval	end;
	int				time_sec;
	int				time_usec;

	usleep(philo->data.time_to_sleep * 1000);
	gettimeofday(&end, NULL);
	time_sec = (end.tv_sec - philo->data.begin.tv_sec) * 1000;
	time_usec = (end.tv_usec - philo->data.begin.tv_usec) / 1000;
	philo->data.time = time_sec + time_usec;
	printf("%d ms ", philo->data.time);
	printf("%d is sleeping\n", philo->id);
	philo->time_not_eat += philo->data.time;
}

void	thinking(t_philo *philo)
{
	struct timeval	end;
	int				time_sec;
	int				time_usec;

	gettimeofday(&end, NULL);
	time_sec = (end.tv_sec - philo->data.begin.tv_sec) * 1000;
	time_usec = (end.tv_usec - philo->data.begin.tv_usec) / 1000;
	philo->data.time = time_sec + time_usec;
	printf("%d ms ", philo->data.time);
	printf("%d is thinking\n", philo->id);
	philo->time_not_eat += philo->data.time;
}

void	do_others(t_philo *philo)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	if (time.tv_usec % 2 == 0)
		sleeping(philo);
	else if (time.tv_usec % 2 != 0)
		thinking(philo);
}

void	*excute_routines(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	take_fork(arg);
	do_others(philo);
	return (NULL);
}
