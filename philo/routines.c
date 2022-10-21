/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:43:29 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/21 23:44:09 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_data *data, t_philo *philo)
{
	pthread_mutex_t	lock;

	lock = philo->lock;
	pthread_mutex_lock(&lock);
	if (data->fork[philo->id - 1] != 0 && data->fork[philo->id] != 0)
	{
		data->fork[philo->id - 1] = 0;
		data->fork[philo->id] = 0;
		printf("%d has taken a fork\n", philo->id);
		philo->fork += 2;
		data->num_fork -= 2;
	}
	//printf("num fork : %d\n", data->num_fork);
	pthread_mutex_unlock(&lock);
}

void	sleeping(int arg)
{
	printf("%d is sleeping\n", arg);
}

void	thinking(int arg)
{
	printf("%d is thinking\n", arg);
}

void	do_others(int arg)
{
	if (arg % 2 == 0)
		sleeping(arg);
	else if (arg % 2 != 0)
		thinking(arg);
}

void	*excute_routines(t_data data, t_philo *philo)
{
	int	i;
	// struct timeval begin;
	// struct timeval end;

	i = 0;
	printf("philo : %d\n", data.num_philo);
	while (i < data.num_philo && data.num_fork)
	{
		take_fork(&data, &philo[i]);
		printf("fork : %d\n", data.num_fork);
		i++;
	}
	// do_others();
	return (NULL);
}
