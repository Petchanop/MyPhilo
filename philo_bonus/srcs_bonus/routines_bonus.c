/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:23:00 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/25 14:19:46 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	choose_fork(t_philo *philo, sem_t *mutex)
{
	get_time(philo);
	sem_wait(mutex);
	philo->fork++;
	philo->data->num_fork--;
	print_time(philo, "has taken a fork\n");
}

void	drop_fork(t_philo *philo, sem_t *mutex)
{
	philo->fork--;
	philo->data->num_fork++;
	sem_post(mutex);
}

void	eating(t_philo *philo)
{
	int	fork;

	fork = philo->data->num_fork;
	if (!philo->die && philo->data->num_philo != philo->data->eat)
	{
		print_time(philo, "is eating\n");
		take_time(philo, philo->data->time_to_eat);
		sem_wait(philo->data->lock);
		philo->time_eat = philo->time;
		get_time(philo);
		philo->num_eat++;
		if (philo->num_eat == philo->data->num_must_eat)
			philo->data->eat++;
		philo->time_not_eat = 0;
		sem_post(philo->data->lock);
	}
}

void	take_fork(t_philo *philo)
{
	int	fork;

	fork = philo->data->num_fork;
	get_time(philo);
	if (fork <= 1)
		take_time(philo, philo->data->time_to_eat);
	if (fork > 1 && !philo->data->die
		&& philo->data->num_philo != philo->data->eat)
	{
		choose_fork(philo, philo->data->fork);
		choose_fork(philo, philo->data->fork);
		eating(philo);
		drop_fork(philo, philo->data->fork);
		drop_fork(philo, philo->data->fork);
	}
}
