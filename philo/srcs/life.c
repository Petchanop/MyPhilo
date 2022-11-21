/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:33:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/19 15:07:46 by npiya-is         ###   ########.fr       */
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
	if (philo->data->num_philo == philo->data->eat)
	{
		if (!pthread_mutex_lock(&philo->data->lock))
		{
			get_time(philo);
			printf("%d ms All philo was eat enough\n", philo->data->time);
		}
	}
	else
		print_time(&philo[i], "died\n");
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
		i += 2;
		if (i >= data->num_fork && i % 2 == 0)
		{
			i = 1;
			usleep(50);
		}
	}
	monitor_die(th);
	pthread_mutex_unlock(&data->lock);
}
