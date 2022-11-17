/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:43:29 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/16 22:37:35 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	eating(t_philo *philo)
{
	int	fork;

	fork = philo->fork;
	// check_die(philo);
	philo->fork++;
	print_time(philo, "has taken a fork\n");
	philo->fork++;
	print_time(philo, "has taken a fork\n");
	if (philo->fork == 2)
	{
		print_time(philo, "is eating\n");
		take_time(philo, philo->data->time_to_eat);
		philo->time_eat = philo->data->time;
		get_time(philo);
		philo->num_eat++;
		philo->time_not_eat = 0;
		philo->fork = 0;
	}
}

void	take_fork(t_philo *philo)
{
	int	fork;

	fork = philo->data->num_fork;
	get_time(philo);
	// if (philo->id % 2 == 0)
	// 	take_time(philo, philo->data->time_to_eat);
	// check_die(philo);
	if (!philo->die
		&& !pthread_mutex_lock(&philo->data->fork[philo->id - 1])
		&& !pthread_mutex_lock(&philo->data->fork[philo->id % fork]))
	{
		eating(philo);
		pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
		pthread_mutex_unlock(&philo->data->fork[philo->id % fork]);
	}
	// check_die(philo);
}

void	sleeping(t_philo *philo)
{
	if (!philo->die)// && !pthread_mutex_lock(&philo->data->sleep))
	{
		print_time(philo, "is sleeping\n");
		take_time(philo, philo->data->time_to_sleep);
		//check_die(philo);
		//pthread_mutex_unlock(&philo->data->sleep);
	}
}

void	thinking(t_philo *philo)
{
	if (!philo->die)// && !pthread_mutex_lock(&philo->data->thinking))
	{
		print_time(philo, "is thinking\n");
		// check_die(philo);
		//pthread_mutex_unlock(&philo->data->thinking);
	}
}

void	do_others(t_philo *philo)
{
	sleeping(philo);
	thinking(philo);
}
