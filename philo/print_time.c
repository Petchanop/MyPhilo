/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:31:07 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/23 17:33:17 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_time(t_philo *philo)
{
	struct timeval	end;
	int				time_sec;
	int				time_usec;

	gettimeofday(&end, NULL);
	time_sec = (end.tv_sec - philo->data.begin.tv_sec) * 1000;
	time_usec = (end.tv_usec - philo->data.begin.tv_usec) / 1000;
	philo->data.time = time_sec + time_usec;
	printf("%d ms ", philo->data.time);
}
