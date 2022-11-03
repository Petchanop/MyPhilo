/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:43:29 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/03 20:41:09 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	*eating(t_philo *philo)
{
	int	fork;
	int	*die;

	die = check_die(philo);
	if (die != NULL)
		return (die);
	fork = philo->fork;
	philo->fork++;
	print_time(philo, "has taken a fork\n");
	philo->fork++;
	print_time(philo, "has taken a fork\n");
	if (philo->fork == 2 && pthread_mutex_lock(&philo->data->que) == 0)
	{
		print_time(philo, "is eating\n");
		usleep(philo->data->time_to_eat * 1000);
		philo->time_eat = philo->data->time + philo->data->time_to_eat;
		philo->num_eat++;
		philo->time_not_eat = 0;
		philo->fork = 0;
		pthread_mutex_unlock(&philo->data->que);
	}
	return (NULL);
}

int	*take_fork(t_philo *philo)
{
	int	fork;
	int	lock1;
	int	lock2;
	int	*die;

	die = check_die(philo);
	if (die != NULL)
		return (die);
	fork = philo->data->num_fork;
	lock1 = pthread_mutex_lock(&philo->data->fork[philo->id - 1]);
	lock2 = pthread_mutex_lock(&philo->data->fork[philo->id % fork]);
	die = check_die(philo);
	if (die != NULL)
		return (die);
	if (!lock1 && !lock2)
	{
		die = eating(philo);
		if (die != NULL)
			return (die);
		pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
		pthread_mutex_unlock(&philo->data->fork[philo->id % fork]);
	}
	else
	{
		if (lock1)
			pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
		if (lock2)
			pthread_mutex_unlock(&philo->data->fork[philo->id % fork]);
	}
	return (do_others(philo));
}

int	*sleeping(t_philo *philo)
{
	print_time(philo, "is sleeping\n");
	usleep(philo->data->time_to_sleep * 1000);
	get_time(philo);
	philo->time_not_eat += (philo->data->time - philo->time_eat);
	return (check_die(philo));
}

int	*thinking(t_philo *philo)
{
	print_time(philo, "is thinking\n");
	get_time(philo);
	philo->time_not_eat += (philo->data->time - philo->time_eat);
	return (check_die(philo));
}

int	*do_others(t_philo *philo)
{
	int	*die;
	int	*dies;

	die = sleeping(philo);
	dies = thinking(philo);
	if (die != NULL)
		return (die);
	if (dies != NULL)
		return (die);
	else if (die == NULL)
		return (die);
	else if (dies == NULL)
		return (dies);
	return (NULL);
}
