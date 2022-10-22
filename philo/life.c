/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:33:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/22 20:29:07 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	do_routines(t_data data, t_philo *th)
{
	int	i;
	int	j;
	int	err;
	struct timeval	begin;
	struct timeval	end;
	int				time_sec;
	int				time_usec;

	i = 0;
	j = 0;
	err = 0;
	gettimeofday(&begin, NULL);
	data.begin = begin;
	while (j < 1000)
	{
		gettimeofday(&end, NULL);
		time_sec = (end.tv_sec - begin.tv_sec) * 1000;
		time_usec = (end.tv_usec - begin.tv_usec) / 1000;
		data.time = time_sec + time_usec;
		if (j < data.num_fork)
			err = pthread_create(&th[i].philo, NULL, excute_routines, &th[i]);
		if (err != 0)
			printf("Can't create thread number %d\n", i);
		if (th[i].die)
			break ;
		i++;
		j++;
	}
	i = 0;
	while (i < data.num_fork)
	{
		if (i < data.num_fork)
			pthread_join(th[i].philo, NULL);
		i++;
	}
}
