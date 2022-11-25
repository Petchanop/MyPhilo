/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:01:13 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/15 22:10:16 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char *argv[])
{
	t_philo		*philo;
	t_data		data;

	if (argc >= 1)
	{
		initialize_data(&data, argv);
		printf("num_fork 	: %d\n", data.num_fork);
		printf("time_to_die 	: %d\n", data.time_to_die);
		printf("time_to_eat	: %d\n", data.time_to_eat);
		printf("time_to_sleep 	: %d\n", data.time_to_sleep);
		printf("num_must_eat  	: %d\n", data.num_must_eat);
		philo = malloc((ft_atoi(argv[1])) * sizeof(t_philo));
		create_philo(data, philo);
		do_routines(&data, philo);
		sem_close(data.fork);
		sem_close(data.lock);
		sem_unlink("/fork");
		sem_unlink("/lock");
	}
	return (0);
}