/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:01:56 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/28 21:59:31 by npiya-is         ###   ########.fr       */
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
	data->die = 0;
	data->eat = 0;
	if (argv[5])
		data->num_must_eat = ft_atoi(argv[5]);
	else
		data->num_must_eat = 0;
	sem_unlink("/fork");
	sem_unlink("/lock");
	sem_unlink("/print");
	sem_unlink("/eatall");
	data->fork = sem_open("/fork", O_CREAT | O_EXCL, 0666, data->num_philo);
	data->lock = sem_open("/lock", O_CREAT | O_EXCL, 0666, 1);
	data->print = sem_open("/print", O_CREAT | O_EXCL, 0666, 1);
	data->eatall = sem_open("/eatall", O_CREAT | O_EXCL, 0666, data->num_philo);
}

void	assign_data(t_philo *arg)
{
	arg->fork = 0;
	arg->num_eat = 0;
	arg->time_not_eat = 0;
	arg->time_eat = 0;
	arg->die = 0;
}
