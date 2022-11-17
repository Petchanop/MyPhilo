/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:01:56 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/16 15:53:04 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	initialize_data(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->num_philo = ft_atoi(argv[1]);
	data->num_fork = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->dies = NULL;
	data->all_eat = NULL;
	data->eat = 0;
	if (argv[5])
		data->num_must_eat = ft_atoi(argv[5]);
	else
		data->num_must_eat = 0;
	data->fork = sem_open("/fork_mutex", O_CREAT, S_IRUSR | S_IWUSR, 0666, 5);
	data->lock = sem_open("/lock", O_CREAT, S_IRUSR | S_IWUSR, 0666, 1);
}

void	assign_data(t_data *data, t_philo *arg)
{
	arg->data = data;
	arg->fork = 0;
	arg->num_eat = 0;
	arg->time_not_eat = 0;
	arg->time_eat = 0;
}
