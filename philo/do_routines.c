/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_routines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:09:09 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/09 22:12:01 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	*check_die(t_philo *philo)
{
	int	*re;

	re = NULL;
	get_time(philo);
	if (philo->time_not_eat >= philo->data->time_to_die
		|| (philo->data->num_must_eat
			&& philo->num_eat == philo->data->num_must_eat))
	{
		pthread_mutex_lock(&philo->data->lock);
		re = malloc(sizeof(int));
		*re = philo->id;
		philo->dies = 1;
		//pthread_mutex_unlock(&philo->data->lock);
		return (re);
	}
	return (re);
}

void	*excute_routines(void *arg)
{
	t_philo		*philo;
	int			*die;

	philo = (t_philo *)arg;
	get_time(philo);
	die = take_fork(philo);
	if (die)
		return ((void *)die);
	die = check_die(philo);
	if (die)
		return ((void *)die);
	else
		excute_routines(arg);
	return (NULL);
}
