/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:07:46 by zderfouf          #+#    #+#             */
/*   Updated: 2024/04/02 12:24:15 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool 	pure_numbers(char **av)
{
	int i;
	int j;

	i = -1;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] =='+' || av[i][j] == '-') && !j) // '-' in case of -0
				j++;
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (false);
		}
		if(ft_atol(av[i]) < 0)
			return(false);
	}
	return (true);
}

void    parsing(int ac, char **av)
{
	t_philo	philo;

	if (!pure_numbers(av + 1))
	{
		printf("PARSER\n");
		exit(1);
	}
	else
		printf("NICE !!\n");

	// printf("%d\n",ft_atol(av[1]));
	// printf("%d\n",ft_atol(av[2]));
	// printf("%d\n",ft_atol(av[3]));
	// printf("%d\n",ft_atol(av[4]));

	// philo.n_philo = ft_atol(av[1]);
	// philo.time_to_die = ft_atol(av[2]);
	// philo.time_to_eat = ft_atol(av[3]);
	// philo.time_to_sleep = ft_atol(av[4]);
	// if (ac == 5)
	// 	philo.meals = ft_atol(av[5]);
}