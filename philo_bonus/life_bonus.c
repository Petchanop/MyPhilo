/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:20:05 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/15 21:55:11 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*monitor_die(void *arg)
{
	t_philo	*philo;
	int		i;
	int		j;
	int		count;

	philo = (t_philo *)arg;
	i = 0;
	while (1)
	{
		if (i == philo->data->num_fork)
			i = 0;
		if (philo[i].data->dies
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
		if (!sem_wait(philo->data->lock))
		{
			i = 0;
			get_time(philo);
			philo->data->all_eat = &philo->id;
			printf("%d ms All philo was eat enough\n", philo->data->time);
			sem_post(philo->data->lock);
		}
	}
	else
		print_time(&philo[i], "died\n");
	i = 0;
	while (i < philo->data->num_fork)
	{
		pthread_detach(philo[i].philo);
		i++;
	}
	return (NULL);
}

void	do_routines(t_data *data, t_philo *th)
{
	int				i;
	struct timeval	begin;
	pthread_t		monitor;

	i = 0;
	monitor = NULL;
	gettimeofday(&begin, NULL);
	data->begin = begin;
	while (i < data->num_fork)
	{
		th[i].data->begin = data->begin;
		if (pthread_create(&th[i].philo, NULL, &excute_routines, &th[i]) != 0)
			printf("Can't create thread number %d\n", i);
		i++;
	}
	pthread_create(&monitor, NULL, &monitor_die, th);
	pthread_join(monitor, NULL);
	pthread_detach(monitor);
}
