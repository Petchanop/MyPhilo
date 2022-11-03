/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:33:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/03 20:29:04 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	mysleep(int sleep)
{
	int		i;

	i = 0;
	while (i < sleep)
	{
		usleep(1);
		i++;
	}
}

void	do_routines(t_data *data, t_philo *th)
{
	int				i;
	void			*res;
	int				err;
	struct timeval	begin;

	i = 0;
	err = 0;
	gettimeofday(&begin, NULL);
	data->begin = begin;
	while (i < data->num_fork)
	{
		th[i].data->begin = data->begin;
		err = pthread_create(&th[i].philo, NULL, &excute_routines, &th[i]);
		if (err != 0)
			printf("Can't create thread number %d\n", i);
		i++;
	}
	i = 0;
	res = 0;
	while (1)
	{
		if (i < data->num_fork)
			pthread_join(th[i].philo, &res);
		if (res)
		{
			printf("%d ms ", th[*(int *)res - 1].time_not_eat);
			printf("%d died\n", *(int *)res);
			i = 0;
			while (i < data->num_fork)
			{
				pthread_detach(th[i].philo);
				pthread_mutex_destroy(&th[i].data->fork[i]);
				i++;
			}
			break ;
		}

		i++;
	}
}
