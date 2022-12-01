/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_routines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:09:09 by npiya-is          #+#    #+#             */
/*   Updated: 2022/12/01 19:50:11 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleeping(t_philo *philo)
{
	if (!philo->data.die && philo->data.num_philo != philo->data.eat)
	{
		print_time(philo, "is sleeping\n");
		take_time(philo, philo->data.time_to_sleep);
	}
}

void	thinking(t_philo *philo)
{
	if (!philo->data.die && philo->data.num_philo != philo->data.eat)
		print_time(philo, "is thinking\n");
}

int	check_philo(t_philo *philo, t_data *data)
{
	get_time(philo);
	if ((int)(philo->time - philo->time_eat) >= data->time_to_die)
	{
		data->die = philo->id;
		philo->die = philo->id;
		return (1);
	}
	if (philo->num_eat == philo->data.num_must_eat)
		philo->data.eat++;
	if (philo->data.num_philo == philo->data.eat)
	{
		usleep(1000);
		return (1);
	}
	return (0);
}

void	take_time(t_philo *philo, int ac)
{
	unsigned int	time;
	unsigned int	cur_time;

	get_time(philo);
	cur_time = philo->time;
	time = cur_time + ac;
	while (cur_time < time)
	{
		get_time(philo);
		cur_time = philo->time;
	}
	get_time(philo);
}

void	*excute_routines(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		take_time(philo, philo->data.time_to_eat);
	while (!philo->data.die && (philo->data.num_philo != philo->data.eat))
	{
		take_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}
