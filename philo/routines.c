/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:43:29 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/09 21:55:26 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	*eating(t_philo *philo)
{
	int	fork;
	int	*die;

	fork = philo->fork;
	die = check_die(philo);
	if (die != NULL)
		return (die);
	philo->fork++;
	print_time(philo, "has taken a fork\n");
	philo->fork++;
	print_time(philo, "has taken a fork\n");
	if (philo->fork == 2)
	{
		print_time(philo, "is eating\n");
		usleep(philo->data->time_to_eat * 1000);
		get_time(philo);
		philo->time_eat = philo->data->time;
		philo->num_eat++;
		philo->time_not_eat = 0;
		philo->fork = 0;
	}
	return (NULL);
}

int	*take_fork(t_philo *philo)
{
	int	fork;
	int	*die;

	fork = philo->data->num_fork;
	get_time(philo);
	die = check_die(philo);
	if (die != NULL)
		return (die);
	if (!pthread_mutex_lock(&philo->data->fork[philo->id - 1])
		&& !pthread_mutex_lock(&philo->data->fork[philo->id % fork]))
	{
		die = eating(philo);
		if (die != NULL)
			return (die);
		pthread_mutex_unlock(&philo->data->fork[philo->id - 1]);
		pthread_mutex_unlock(&philo->data->fork[philo->id % fork]);
	}
	die = check_die(philo);
	if (die != NULL)
		return (die);
	return (do_others(philo));
}

int	*sleeping(t_philo *philo)
{
	print_time(philo, "is sleeping\n");
	usleep(philo->data->time_to_sleep * 1000);
	return (check_die(philo));
}

int	*thinking(t_philo *philo)
{
	print_time(philo, "is thinking\n");
	return (check_die(philo));
}

int	*do_others(t_philo *philo)
{
	int	*die;
	int	*dies;

	die = sleeping(philo);
	if (die != NULL)
		return (die);
	dies = thinking(philo);
	if (dies != NULL)
		return (dies);
	return (NULL);
}
