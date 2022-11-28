/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:25:37 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/28 20:54:55 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	get_time(t_philo *philo, t_data data)
{
	struct timeval	end;
	int				time_sec;
	int				time_usec;

	gettimeofday(&end, NULL);
	time_sec = (end.tv_sec - data.begin.tv_sec) * 1000;
	time_usec = (end.tv_usec - data.begin.tv_usec) / 1000;
	philo->time = time_sec + time_usec;
	philo->time_not_eat = philo->time - philo->time_eat;
}

void	print_time(t_philo *philo, char *param, t_data data)
{
	if (!data.die && data.num_philo != data.eat)
	{
		sem_wait(data.print);
		get_time(philo, data);
		printf("%s", assign_color(param));
		printf("%d ms %d %s", philo->time, philo->id, param);
		printf(WHITE);
		sem_post(data.print);
	}
	else
		return ;
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
