/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:07:46 by zderfouf          #+#    #+#             */
/*   Updated: 2024/04/01 10:49:44 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool 	f(char *av)
{
	int i;

	i = -1;

	while (av[++i])
		if (!(av[i] >= '0' && av[i] <= '9'))
		{
			return (false);
		}
	return (true);
}

void    parsing(int ac, char **av)
{
	t_philo	philo;
		
	philo.n_philo = ft_atol(av[1]);
	philo.time_to_die = ft_atol(av[2]);
	philo.time_to_eat = ft_atol(av[3]);
	philo.time_to_sleep = ft_atol(av[4]);
	if (ac == 5)
		philo.meals = ft_atol(av[5]);
}