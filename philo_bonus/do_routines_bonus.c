/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_routines_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:16:27 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/15 21:54:54 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	check_die(t_philo *philo)
{
	int	i;

	i = 0;
	get_time(philo);
	if (philo->time_not_eat >= philo->data->time_to_die || philo->data->all_eat)
	{
		sem_wait(philo->data->lock);
		philo->data->dies = &philo->id;
		sem_post(philo->data->lock);
	}
}

void	take_time(t_philo *philo, int ac)
{
	unsigned int	time;
	unsigned int	cur_time;

	get_time(philo);
	cur_time = philo->data->time;
	time = cur_time + ac;
	while (cur_time <= time)
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