/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:33:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/24 17:53:31 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	do_routines(t_data data, t_philo *th)
{
	int				i;
	int				*res;
	int				err;
	struct timeval	begin;

	i = 0;
	err = 0;
	gettimeofday(&begin, NULL);
	data.begin = begin;
	while (i < data.num_fork)
	{
		th[i].data.begin = data.begin;
		err = pthread_create(&th[i].philo, NULL, &excute_routines, &th[i]);
		if (err != 0)
			printf("Can't create thread number %d\n", i);
		usleep(500);
		i++;
	}
	i = 0;
	res = NULL;
	while (1)
	{
		if (i < data.num_fork)
			pthread_join(th[i].philo, (void *)res);
		if (th[i].time_not_eat >= data.time_to_die)
			break ;
		if (i == data.num_fork)
			i = 0;
		printf("res : %d\n", *res);
		if (*res)
		{
			printf("res : %d\n", *res);
			// i = 0;
			// while (i < data.num_fork)
			// 	pthread_detach(th[i++].philo);
			// break ;
		}
		usleep(500);
		i++;
	}
}
