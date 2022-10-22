/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:43:29 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/22 20:27:26 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(void *arg)
{
	int				fork;
	t_philo			*philo;

	philo = (t_philo *)arg;
	//printf("%d ms ", philo->data.time);
	fork = philo->data.num_fork;
	pthread_mutex_lock(&philo->data.fork[philo->id - 1]);
	pthread_mutex_lock(&philo->data.fork[philo->id % fork]);
	printf("%d ms ", philo->data.time);
	philo->fork++;
	printf("%d has taken a fork\n", philo->id);
	philo->fork++;
	printf("%d ms ", philo->data.time);
	printf("%d has taken a fork\n", philo->id);
	eating(philo);
	pthread_mutex_unlock(&philo->data.fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->data.fork[philo->id % fork]);
}

void	eating(t_philo *philo)
{
	if (philo->fork == 2)
	{
		usleep(philo->data.time_to_eat * 1000);
		printf("%d ms ", philo->data.time);
		printf("%d is eating\n", philo->id);
		philo->fork = 0;
	}
}

void	sleeping(t_philo *philo)
{
	printf("%d ms ", philo->data.time);
	usleep(philo->data.time_to_sleep * 1000);
	printf("%d is sleeping\n", philo->id);
	philo->time_not_eat += philo->data.time;
}

void	thinking(t_philo *philo)
{
	printf("%d ms ", philo->data.time);
	printf("%d is thinking\n", philo->id);
	philo->time_not_eat += philo->data.time / 1000;
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
