/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:31:07 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/19 15:57:55 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	get_time(t_philo *philo)
{
	struct timeval	end;
	int				time_sec;
	int				time_usec;

	gettimeofday(&end, NULL);
	time_sec = (end.tv_sec - philo->data->begin.tv_sec) * 1000;
	time_usec = (end.tv_usec - philo->data->begin.tv_usec) / 1000;
	philo->data->time = time_sec + time_usec;
	philo->time_not_eat = philo->data->time - philo->time_eat;
}

void	print_time(t_philo *philo, char *param)
{
	if (!pthread_mutex_lock(&philo->data->lock))
	{
		get_time(philo);
		printf("%s", assign_color(param));
		printf("%d ms %d %s", philo->data->time, philo->id, param);
		printf(WHITE);
		if (!philo->die || (philo->data->num_philo == philo->data->eat))
			pthread_mutex_unlock(&philo->data->lock);
	}
}

char	*assign_color(char *param)
{
	int	len;

	len = ft_strlen(param);
	if (param[len - 2] == 'k' && param[len - 3] == 'r' && param[len - 4] == 'o')
		return (GREEN);
	else if (param[len - 7] == 'e' && param[len - 6] == 'a'
		&& param[len - 5] == 't')
		return (CYAN);
	else if (param[len - 9] == 't' && param[len - 8] == 'h'
		&& param[len - 7] == 'i')
		return (BLUE);
	else if (param[len - 9] == 's' && param[len - 8] == 'l'
		&& param[len - 7] == 'e')
		return (MAGENTA);
	else if (param[len - 5] == 'd' && param[len - 2] == 'd')
		return (RED);
	return (WHITE);
}
