/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:46:19 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/21 22:47:31 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_philo(t_data data, t_philo *th)
{
	int				i;
	int				err;

	i = 0;
	err = 0;
	while (i < data.num_fork)
	{
		err = pthread_create(&th[i].philo, NULL, &assign_data, &th[i]);
		th[i].id = i + 1;
		if (err != 0)
			printf("Can't create thread number %d\n", i);
		if (pthread_mutex_init(&th[i].lock, NULL) != 0)
			printf("\n mutex init has failed\n");
		usleep(5);
		i++;
	}
	i = 0;
	while (i < data.num_fork)
	{
		pthread_join(th[i].philo, NULL);
		i++;
	}
	i = 0;
	while (i < data.num_fork)
	{
		printf("%p\n", th[i].philo);
		i++;
	}
}
