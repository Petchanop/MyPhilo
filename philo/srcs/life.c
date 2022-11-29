/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:33:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/29 18:58:22 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	monitor_die(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == philo->data->num_fork)
			i = 0;
		if (check_philo(&philo[i]))
			break ;
		i++;
	}
	if (!pthread_mutex_lock(&philo->data->print))
	{
		if (philo->data->num_philo == philo->data->eat)
		{
			get_time(philo);
			printf("%d ms All philo was eat enough\n", philo->time);
		}
		else
			printf("%s%d ms %d has died\n", RED, philo[i].time, philo[i].id);
	}
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_destroy(&philo->data->print);
	return ;
}

void	do_routines(t_data *data, t_philo *th)
{
	int				i;
	struct timeval	begin;

	i = 0;
	gettimeofday(&begin, NULL);
	data->begin = begin;
	while (i < data->num_fork)
	{
		th[i].data->begin = data->begin;
		if (pthread_create(&th[i].philo, NULL, &excute_routines, &th[i]) != 0)
			printf("Can't create thread number %d\n", i);
		i++;
	}
	monitor_die(th);
}
