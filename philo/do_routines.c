/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_routines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:09:09 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/03 20:28:53 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	*check_die(t_philo *philo)
{
	int	*re;

	re = NULL;
	if (philo->time_not_eat >= philo->data->time_to_die
		|| (philo->data->num_must_eat
			&& philo->num_eat == philo->data->num_must_eat))
	{
		pthread_mutex_lock(&philo->data->lock);
		get_time(philo);
		re = malloc(sizeof(int));
		*re = philo->id;
		pthread_mutex_unlock(&philo->data->lock);
		pthread_mutex_destroy(&philo->data->lock);
		return (re);
	}
	return (0);
}

void	*excute_routines(void *arg)
{
	t_philo		*philo;
	int			i;
	int			*die;

	philo = (t_philo *)arg;
	i = 0;
	die = take_fork(philo);
	get_time(philo);
	philo->time_not_eat += (philo->data->time - philo->time_eat);
	die = check_die(philo);
	if (die)
		return ((void *)die);
	else
		excute_routines(arg);
	return (NULL);
}
