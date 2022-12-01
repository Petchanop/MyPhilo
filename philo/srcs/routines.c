/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:43:29 by npiya-is          #+#    #+#             */
/*   Updated: 2022/12/01 19:51:42 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	choose_fork(t_philo *philo, pthread_mutex_t *mutex)
{
	get_time(philo);
	pthread_mutex_lock(mutex);
	philo->fork++;
	print_time(philo, "has taken a fork\n");
}

void	drop_fork(t_philo *philo, pthread_mutex_t *mutex)
{
	philo->fork--;
	pthread_mutex_unlock(mutex);
}

void	eating(t_philo *philo)
{
	if (!philo->die && philo->data.num_philo != philo->data.eat)
	{
		print_time(philo, "is eating\n");
		take_time(philo, philo->data.time_to_eat);
		philo->time_not_eat = 0;
		philo->time_eat = philo->time;
		philo->num_eat++;
	}
}

void	take_fork(t_philo *philo)
{
	int	fork;

	fork = philo->data.num_fork;
	get_time(philo);
	if (!philo->data.die && philo->data.num_philo != philo->data.eat)
	{
		pthread_mutex_lock(&philo->data.lock);
		choose_fork(philo, &philo->data.fork[philo->id - 1]);
		choose_fork(philo, &philo->data.fork[philo->id % fork]);
		pthread_mutex_unlock(&philo->data.lock);
		eating(philo);
		drop_fork(philo, &philo->data.fork[philo->id - 1]);
		drop_fork(philo, &philo->data.fork[philo->id % fork]);
	}
}
