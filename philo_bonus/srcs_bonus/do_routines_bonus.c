/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_routines_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:16:27 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/28 23:13:52 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	sleeping(t_philo *philo, t_data data)
{
	if (!data.die && data.num_philo != data.eat)
	{
		print_time(philo, "is sleeping\n", data);
		take_time(philo, data.time_to_sleep, data);
	}
}

void	thinking(t_philo *philo, t_data data)
{
	if (!data.die && data.num_philo != data.eat)
		print_time(philo, "is thinking\n", data);
}

void	check_philo(t_philo *philo, t_data data)
{
	get_time(philo, data);
	if (philo->time_not_eat >= data.time_to_die)
	{
		data.die = philo->id;
		philo->die = philo->id;
		sem_wait(data.print);
		printf("%s%d ms %d has died\n", RED, philo->time, philo->id);
		exit(EXIT_SUCCESS);
	}
	if (data.num_must_eat && philo->num_eat == data.num_must_eat)
		exit(philo->id);
}

void	take_time(t_philo *philo, int ac, t_data data)
{
	unsigned int	time;
	unsigned int	cur_time;

	get_time(philo, data);
	cur_time = philo->time;
	time = cur_time + ac;
	while (cur_time < time)
	{
		get_time(philo, data);
		cur_time = philo->time;
		check_philo(philo, data);
	}
	get_time(philo, data);
}

void	*excute_routines(t_philo *philo, t_data data)
{
	if (data.num_fork == 1)
		take_time(philo, data.time_to_die, data);
	while (!data.die && (data.num_philo != data.eat))
	{
		take_fork(philo, data);
		sleeping(philo, data);
		thinking(philo, data);
	}
	return (NULL);
}
