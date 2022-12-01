/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:33:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/12/01 20:29:39 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	monitor_die(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == data->num_fork)
			i = 0;
		if (check_philo(&philo[i], data))
			break ;
		i++;
	}
	if (!pthread_mutex_lock(&philo->data.print))
	{
		if (philo->data.num_philo == data->eat)
		{
			get_time(philo);
			printf("%lu ms All philo was eat enough\n", philo->time);
		}
		else
			printf("%s%lu ms %d has died\n", RED, philo[i].time, philo[i].id);
	}
	pthread_mutex_unlock(&philo->data.print);
	pthread_mutex_destroy(&philo->data.print);
}

void	do_routines(t_data *data, t_philo *th)
{
	int				i;
	struct timeval	begin;

	i = 0;
	gettimeofday(&begin, NULL);
	data->begin = begin.tv_sec * 1000000 + begin.tv_usec;
	data->begin /= 1000;
	while (i < data->num_fork)
	{
		th[i].begin = data->begin;
		if (pthread_create(&th[i].philo, NULL, &excute_routines, &th[i]) != 0)
			printf("Can't create thread number %d\n", i);
		i++;
	}
	monitor_die(th, data);
}
