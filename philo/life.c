/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:33:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/16 22:44:27 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_die(t_philo *philo)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	while (1)
	{
		if (i == philo->data->num_fork)
			i = 0;
		if (philo[i].die
			|| (philo->data->num_must_eat
				&& count == philo->data->num_fork))
			break ;
		if (philo[i].num_eat >= philo->data->num_must_eat)
		{
			j = 0;
			count = 0;
			while (j < philo->data->num_fork)
			{
				if (philo[j].num_eat >= philo->data->num_must_eat)
					count++;
				j++;
			}
		}
		i++;
	}
	if (philo->data->num_must_eat && philo->data->eat == philo->data->num_fork)
	{
		if (!pthread_mutex_lock(&philo->data->lock))
		{
			i = 0;
			while (i < philo->data->num_fork)
			{
				pthread_mutex_lock(&philo->data->fork[i]);
				i++;
			}
			get_time(philo);
			philo->data->all_eat = &philo->id;
			printf("%d ms All philo was eat enough\n", philo->data->time);
			pthread_mutex_unlock(&philo->data->lock);
		}
	}
	else
		print_time(&philo[i], "died\n");
	return (NULL);
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
			usleep(100);
		}
	}
	monitor_die(th);
	i = 0;
	while (i < data->num_fork)
	{
		pthread_detach(th[i].philo);
		i++;
	}
}
