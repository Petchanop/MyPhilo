/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:20:05 by npiya-is          #+#    #+#             */
/*   Updated: 2022/12/02 11:47:56 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	clear_process(t_philo *philo, t_data data)
{
	int	i;

	i = 0;
	while (i < data.num_philo)
	{
		kill(philo[i].philo, SIGKILL);
		i++;
	}
	i = 0;
	while (i < data.num_philo)
	{
		kill(philo[i].philo, SIGTERM);
		i++;
	}
}

void	monitor_die(t_philo *philo, t_data data)
{
	int	i;
	int	status;
	int	count;

	i = 0;
	count = 0;
	while (1)
	{
		waitpid(0, &status, 0);
		if (WIFEXITED(status))
		{
			if (status == 0)
				break ;
			else if (status > 0)
			{
				count++;
				if (count == data.num_philo)
				{
					get_time(philo, data);
					printf("%s%d ms All philo eat enough\n", WHITE, philo->time);
					break ;
				}
			}
		}
	}
}

void	buid_process(t_data data, t_philo *th)
{
	int				i;
	struct timeval	begin;

	i = 0;
	gettimeofday(&begin, NULL);
	data.begin = begin.tv_sec * 1000000 + begin.tv_usec;
	data.begin /= 1000;
	while (i < data.num_philo)
	{
		th[i].begin = data.begin;
		do_routines(data, &th[i]);
		i++;
	}
	monitor_die(th, data);
	clear_process(th, data);
}

void	do_routines(t_data data, t_philo *philo)
{
	int				i;

	i = 0;
	philo->philo = fork();
	if (philo->philo == 0)
		excute_routines(philo, data);
}
