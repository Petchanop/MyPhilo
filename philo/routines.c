/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:43:29 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/19 15:57:47 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	int	fork;

	fork = philo->fork;
	philo->fork++;
	print_time(philo, "has taken a fork\n");
	philo->fork++;
	print_time(philo, "has taken a fork\n");
	if ((!philo->die && philo->data->num_philo != philo->data->eat)
		&& philo->fork == 2)
	{
		print_time(philo, "is eating\n");
		take_time(philo, philo->data->time_to_eat);
		philo->time_eat = philo->data->time;
		get_time(philo);
		philo->num_eat++;
		pthread_mutex_lock(&philo->data->lock);
		if (philo->num_eat == philo->data->num_must_eat)
			philo->data->eat++;
		pthread_mutex_unlock(&philo->data->lock);
		philo->time_not_eat = 0;
		philo->fork = 0;
	}
}

void	take_fork(t_philo *philo)
{
	int	fork;

	fork = philo->data->num_fork;
	get_time(philo);
	if (!philo->data->die && philo->data->num_philo != philo->data->eat
		&& !pthread_mutex_lock(&philo->data->fork[philo->id - 1])
		&& !pthread_mutex_lock(&philo->data->fork[philo->id % fork]))
	{
		eating(philo);
		pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
		pthread_mutex_unlock(&philo->data->fork[philo->id % fork]);
	}
}

void	sleeping(t_philo *philo)
{
	if (!philo->data->die && philo->data->num_philo != philo->data->eat)
	{
		print_time(philo, "is sleeping\n");
		take_time(philo, philo->data->time_to_sleep);
	}
}

void	thinking(t_philo *philo)
{
	if (!philo->data->die && philo->data->num_philo != philo->data->eat)
		print_time(philo, "is thinking\n");
}

void	do_others(t_philo *philo)
{
	sleeping(philo);
	thinking(philo);
}
