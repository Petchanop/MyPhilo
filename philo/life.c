/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:33:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/22 21:40:30 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	do_routines(t_data data, t_philo *th)
{
	int	i;
	int	j;
	int	err;
	struct timeval	begin;

	i = 0;
	j = 0;
	err = 0;
	gettimeofday(&begin, NULL);
	data.begin = begin;
	while (j < 1000)
	{
		if (j < data.num_fork)
		{
			th[i].data.begin = data.begin;
			err = pthread_create(&th[i].philo, NULL, excute_routines, &th[i]);
		}
		if (err != 0)
			printf("Can't create thread number %d\n", i);
		if (th[i].die)
			break ;
		i++;
		j++;
	}
	i = 0;
	while (1)
	{
		if (i < data.num_fork)
			pthread_join(th[i].philo, NULL);
		else
			i = 0;
		if (th[i].time_not_eat >= data.time_to_die)
		{
			i = 0;
			printf("%d ms ", th[i].data.time);
			printf("%d died\n", th[i].id);
			while (i < data.num_fork)
				pthread_detach(th[i++].philo);
			break ;
		}
		i++;
	}
}
