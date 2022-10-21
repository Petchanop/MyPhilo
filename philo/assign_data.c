/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 20:08:32 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/21 22:58:21 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_data(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->num_philo = ft_atoi(argv[1]);
	data->num_fork = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_must_eat = ft_atoi(argv[5]);
	else
		data->num_must_eat = 0;
	data->fork = malloc(ft_atoi(argv[1]) * sizeof(int));
	while (i < data->num_fork)
	{
		data->fork[i] = 1;
		i++;
	}
}

void	*assign_data(void *arg)
{
	(*(t_philo *)arg).fork = 0;
	(*(t_philo *)arg).die = 0;
	(*(t_philo *)arg).eat = 0;
	(*(t_philo *)arg).sleep = 0;
	(*(t_philo *)arg).num_eat = 0;
	return (arg);
}
