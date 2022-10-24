/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:43:29 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/24 22:33:38 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(void *arg)
{
	int				fork;
	t_philo			*philo;

	philo = (t_philo *)arg;
	fork = philo->data.num_fork;
	pthread_mutex_lock(&philo->data.fork[philo->id - 1]);
	pthread_mutex_lock(&philo->data.fork[philo->id % fork]);
	philo->fork++;
	print_time(philo);
	printf("%d has taken a fork\n", philo->id);
	philo->fork++;
	print_time(philo);
	printf("%d has taken a fork\n", philo->id);
	usleep(5);
	eating(philo);
	pthread_mutex_unlock(&philo->data.fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->data.fork[philo->id % fork]);
	return ;
}

void	eating(t_philo *philo)
{
	int	fork;	

	fork = philo->fork;
	if (philo->fork == 2)
	{
		print_time(philo);
		printf("%d is eating\n", philo->id);
		usleep(philo->data.time_to_eat * 1000);
		philo->time_eat = philo->data.time;
		philo->time_not_eat = 0;
		philo->fork = 0;
	}
	else
		do_others(philo);
}

void	sleeping(t_philo *philo)
{
	print_time(philo);
	printf("%d is sleeping\n", philo->id);
	usleep(philo->data.time_to_sleep * 1000);
	philo->time_not_eat += philo->data.time - philo->time_eat;
}

void	thinking(t_philo *philo)
{
	print_time(philo);
	printf("%d is thinking\n", philo->id);
	philo->time_not_eat += (philo->data.time - philo->time_not_eat);
}

void	do_others(t_philo *philo)
{
	sleeping(philo);
	thinking(philo);
}

void	*excute_routines(void *arg)
{
	t_philo	*philo;
	int		*re;

	philo = (t_philo *)arg;
	re = NULL;
	take_fork(arg);
	do_others(philo);
	if (philo->time_not_eat >= philo->data.time_to_die)
	{
		pthread_mutex_lock(&philo->data.lock);
		re = malloc(sizeof(int));
		*re = philo->id;
		pthread_mutex_unlock(&philo->data.lock);
		pthread_mutex_destroy(&philo->data.lock);
		return ((void *)re);
	}
	return (NULL);
}
