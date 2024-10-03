/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 06:59:47 by zderfouf          #+#    #+#             */
/*   Updated: 2024/10/03 10:18:40 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ac == 5 || ac == 6)
	{
		if (!parsing(av))
			return (1);
		if (!init_data(ac, av, &philo))
			return (1);
		create_philo(philo);
		free_mem(philo);
	}
	else
		return (write(2, "Wrong number of arguments\n", 26), 1);
}
