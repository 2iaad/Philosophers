/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 06:59:47 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/26 12:04:23 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ac == 5 || ac == 6)
	{
		parsing(ac, av);
		init_data(ac, av, &philo);
		create_philo(philo);
		mutex_destroy(philo);
	}
	else
		printf("Wrong number of arguments\n");
}
