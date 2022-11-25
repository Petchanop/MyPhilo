/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:20:05 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/25 14:18:10 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	monitor_die(t_philo *philo)
{
	int	i;

	i = 0;
	while (1)
	{
		if (i == philo->data->num_philo)
			i = 0;
		if (check_philo(&philo[i]))
			break ;
		i++;
	}
	if (!sem_wait(philo->data->print))
	{
		if (philo->data->num_philo == philo->data->eat)
		{
			get_time(philo);
			printf("%d ms All philo was eat enough\n", philo->time);
		}
		else
			printf("%s%d ms %d has died\n", RED, philo[i].time, philo[i].id);
	}
	sem_post(philo->data->print);
	return ;
}

void	do_routines(t_data *data, t_philo *th)
{
	int				i;
	struct timeval	begin;

	i = 0;
	gettimeofday(&begin, NULL);
	data->begin = begin;
	while (i < data->num_philo)
	{
		th[i].data->begin = data->begin;
		if (pthread_create(&th[i].philo, NULL, &excute_routines, &th[i]) != 0)
			printf("Can't create thread number %d\n", i);
		i++;
	}
	monitor_die(th);
}
