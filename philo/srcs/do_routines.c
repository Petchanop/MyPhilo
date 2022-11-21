/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_routines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:09:09 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/19 15:58:15 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_philo(t_philo *philo)
{
	int	i;

	i = 0;
	get_time(philo);
	if (philo->time_not_eat >= philo->data->time_to_die)
	{
		philo->data->die = philo->id;
		philo->die = philo->id;
		return (1);
	}
	if (philo->data->num_philo == philo->data->eat)
		return (1);
	return (0);
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
	}
	get_time(philo);
}

void	*excute_routines(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	take_fork(philo);
	do_others(philo);
	if (!philo->data->die && (philo->data->num_philo != philo->data->eat))
		excute_routines(arg);
	return (arg);
}
