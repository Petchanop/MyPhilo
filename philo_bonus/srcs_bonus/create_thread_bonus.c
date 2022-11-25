/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:18:52 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/15 21:19:38 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	create_philo(t_data data, t_philo *th)
{
	int	i;

	i = 0;
	while (i < data.num_fork)
	{
		assign_data(&data, &th[i]);
		th[i].id = i + 1;
		i++;
	}
	printf("Philo create success\n");
}