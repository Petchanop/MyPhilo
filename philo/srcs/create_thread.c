/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:46:19 by npiya-is          #+#    #+#             */
/*   Updated: 2022/12/01 19:31:24 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_philo(t_data data, t_philo *th)
{
	int	i;

	i = 0;
	while (i < data.num_fork)
	{
		assign_data(data, &th[i]);
		th[i].id = i + 1;
		i++;
	}
}
