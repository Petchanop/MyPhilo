/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiya-is <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:01:13 by npiya-is          #+#    #+#             */
/*   Updated: 2022/11/29 19:13:50 by npiya-is         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_usage(void)
{
	printf("%sUSAGE :\n", CYAN);
	printf("\tnumber_of_philosophers\n");
	printf("\ttime_to_die\n");
	printf("\ttime_to_eat\n");
	printf("\ttime_to_sleep\n");
	printf("\toptional : [number_of_times_each_philosopher_must_eat]\n%s", WHITE);
	printf("%sinput must be positive number.\n", RED);
	printf("number of philo must be not over 200.\n%s", WHITE);
	printf("%s%sex. ./philo 2 400 200 200\n%s", BLUE, GREENBG, WHITE);
}

int	main(int argc, char *argv[])
{
	t_philo		*philo;
	t_data		data;

	if (argc >= 5 && argc < 7)
	{
		if (!check_input(argc, argv))
		{
			print_usage();
			return (0);
		}
		initialize_data(&data, argv);
		philo = malloc((ft_atoi(argv[1])) * sizeof(t_philo));
		create_philo(data, philo);
		buid_process(data, philo);
		sem_close(data.fork);
		sem_close(data.lock);
		sem_close(data.print);
		free(philo);
	}
	else
		print_usage();
	return (0);
}
