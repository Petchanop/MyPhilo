/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:46:19 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/08 05:01:12 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_philo(int philo, pthread_t *th)
{
	int	i;

	i = 0;
	while (i < philo)
	{
		pthread_create(th + i, NULL, &take_fork, NULL);
		pthread_join(th[i], NULL);
		i++;
	}
}