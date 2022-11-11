/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_routines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:09:09 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/11 17:06:46 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_die(t_philo *philo)
{
	int	i;

	i = 0;
	get_time(philo);
	if (philo->time_not_eat >= philo->data->time_to_die
		|| (philo->data->num_must_eat
			&& philo->num_eat == philo->data->num_must_eat))
	{
		pthread_mutex_lock(&philo->data->lock);
		philo->data->dies = &philo->id;
		pthread_mutex_unlock(&philo->data->lock);
		while (i < philo->data->num_fork)
		{
			pthread_mutex_lock(&philo->data->fork[i]);
			i++;
		}
		pthread_mutex_destroy(&philo->data->lock);
	}
}

void	take_time(t_philo *philo, int ac)
{
	unsigned int	time;
	unsigned int	cur_time;

	get_time(philo);
	cur_time = philo->data->time;
	time = cur_time + ac;
	while (cur_time < time)
	{
		get_time(philo);
		cur_time = philo->data->time;
		check_die(philo);
	}
}

void	*excute_routines(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	get_time(philo);
	take_fork(philo);
	do_others(philo);
	check_die(philo);
	if (!philo->data->dies)
		excute_routines(arg);
	return (arg);
}
