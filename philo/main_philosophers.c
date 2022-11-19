/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:22:13 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/19 15:57:44 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	t_philo		*philo;
	t_data		data;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (argc >= 1)
	{
		initialize_data(&data, argv);
		philo = malloc((ft_atoi(argv[1])) * sizeof(t_philo));
		create_philo(data, philo);
		do_routines(&data, philo);
		while (j < data.num_fork)
		{
			pthread_mutex_destroy(data.fork);
			j++;
		}
		free(data.fork);
	}
	return (0);
}
/*
	printf("num_fork 	: %d\n", data.num_fork);
	printf("time_to_die 	: %d\n", data.time_to_die);
	printf("time_to_eat	: %d\n", data.time_to_eat);
	printf("time_to_sleep 	: %d\n", data.time_to_sleep);
	printf("num_must_eat  	: %d\n", data.num_must_eat);
*/