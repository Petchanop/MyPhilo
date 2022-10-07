/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 01:22:13 by npiya-is          #+#    #+#             */
/*   Updated: 2022/10/08 01:55:52 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char *argv[])
{
	pthread_t	*philo;

	if (argc >= 4)
	{
		philo = malloc((ft_atoi(argv[1])) * sizeof(pthread_t));
		create_philo(ft_atoi(argv[1]), philo);
	}
	return (0);
}