/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:33:02 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/11 17:23:30 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor_die(void *arg)
{
	t_philo	*philo;
	int		i;
	int		*re;

	philo = (t_philo *)arg;
	i = 0;
	while (1)
	{
		if (i == philo->data->num_fork)
			i = 0;
		if (philo[i].data->dies)
			break ;
		i++;
	}
	re = malloc(sizeof(int));
	*re = *philo[i].data->dies;
	i = 0;
	while (i < philo->data->num_fork)
	{
		pthread_detach(philo[i].philo);
		i++;
	}
	return ((void *)re);
}

void	do_routines(t_data *data, t_philo *th)
{
	int				i;
	void			*res;
	struct timeval	begin;
	pthread_t		monitor;

	i = 0;
	monitor = NULL;
	gettimeofday(&begin, NULL);
	data->begin = begin;
	while (i < data->num_fork)
	{
		th[i].data->begin = data->begin;
		if (pthread_create(&th[i].philo, NULL, &excute_routines, &th[i]) != 0)
			printf("Can't create thread number %d\n", i);
		i++;
	}
	res = 0;
	pthread_create(&monitor, NULL, &monitor_die, th);
	pthread_join(monitor, &res);
	if ((int *)res)
		print_time(&th[*(int *)res - 1], "died\n");
	pthread_detach(monitor);
	free(res);
}
