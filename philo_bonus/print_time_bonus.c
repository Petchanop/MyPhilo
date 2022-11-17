/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:25:37 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/15 22:17:29 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	get_time(t_philo *philo)
{
	struct timeval	end;
	int				time_sec;
	int				time_usec;

	gettimeofday(&end, NULL);
	time_sec = (end.tv_sec - philo->data->begin.tv_sec) * 1000;
	time_usec = (end.tv_usec - philo->data->begin.tv_usec) / 1000;
	philo->data->time = time_sec + time_usec;
	philo->time_not_eat = philo->data->time - philo->time_eat;
}

void	print_time(t_philo *philo, char *param)
{
	if (!sem_wait(philo->data->lock))
	{
		get_time(philo);
		printf("%d ms %d %s", philo->data->time, philo->id, param);
		sem_post(philo->data->lock);
	}
}
