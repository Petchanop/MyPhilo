/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:23:00 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/30 19:53:33 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	choose_fork(t_philo *philo, sem_t *mutex, t_data data)
{
	sem_wait(mutex);
	print_time(philo, "has taken a fork\n", data);
}

void	drop_fork(t_philo *philo, sem_t *mutex)
{
	philo->fork--;
	sem_post(mutex);
}

void	eating(t_philo *philo, t_data data)
{
	int	fork;

	fork = data.num_fork;
	if (!philo->die && data.num_philo != data.eat)
	{
		print_time(philo, "is eating\n", data);
		take_time(philo, data.time_to_eat, data);
		sem_wait(data.eatall);
		philo->time_eat = philo->time;
		get_time(philo, data);
		philo->num_eat++;
		if (philo->num_eat == data.num_must_eat)
			data.eat++;
		philo->time_not_eat = 0;
		sem_post(data.eatall);
	}
}

void	take_fork(t_philo *philo, t_data data)
{
	int	fork;

	fork = data.num_fork;
	get_time(philo, data);
	if (!data.die && data.num_philo != data.eat)
	{
		sem_wait(data.lock);
		choose_fork(philo, data.fork, data);
		choose_fork(philo, data.fork, data);
		sem_post(data.lock);
		eating(philo, data);
		drop_fork(philo, data.fork);
		drop_fork(philo, data.fork);
	}
}
