/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:22:13 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/28 23:41:19 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_usage(void)
{
	printf("USAGE :\n");
	printf("\tnumber_of_philosophers\n");
	printf("\ttime_to_die\n");
	printf("\ttime_to_eat\n");
	printf("\ttime_to_sleep\n");
	printf("\toptional : [number_of_times_each_philosopher_must_eat]\n");
	printf("input must be positive number.\n");
	printf("number of philo must be not over 200.\n");
	printf("ex. ./philo 2 400 200 200\n");
}

int	main(int argc, char *argv[])
{
	t_philo		*philo;
	t_data		data;
	int			i;

	i = 0;
	if (argc >= 5 && argc < 7)
	{
		initialize_data(&data, argv);
		philo = malloc((ft_atoi(argv[1])) * sizeof(t_philo));
		create_philo(data, philo);
		do_routines(&data, philo);
		free(data.fork);
	}
	else
		print_usage();
	return (0);
}

/*
	printf("num_fork 	: %d\n", data.num_fork);
	printf("time_to_die 	: %d\n", data.time_to_die);
	printf("time_to_eat	: %d\n", data.time_to_eat);
	printf("time_to_sleep 	: %d\n", data.time_to_sleep);
	printf("num_must_eat  	: %d\n", data.num_must_eat);
*/