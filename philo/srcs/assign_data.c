/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:08:32 by npiya-is          #+#    #+#             */
/*   Updated: 2022/12/01 19:31:19 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 1)
			return (0);
		i++;
	}
	return (1);
}

void	initialize_data(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->num_philo = ft_atoi(argv[1]);
	data->num_fork = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->eat = 0;
	data->die = 0;
	if (argv[5])
		data->num_must_eat = ft_atoi(argv[5]);
	else
		data->num_must_eat = 0;
	data->fork = malloc((data->num_fork) * sizeof(pthread_mutex_t));
	while (i < data->num_fork)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			printf("\nmutex init has failed\n");
		i++;
	}
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->lock2, NULL);
	pthread_mutex_init(&data->print, NULL);
}

void	assign_data(t_data data, t_philo *arg)
{
	arg->data = data;
	arg->fork = 0;
	arg->num_eat = 0;
	arg->time_not_eat = 0;
	arg->time_eat = 0;
	arg->die = 0;
	arg->eat = 0;
}
