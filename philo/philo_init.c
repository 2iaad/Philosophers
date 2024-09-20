/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:54:57 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/20 20:52:37 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	assign_forks(t_philo *philos)
{
	int i;

	i = 0;
	philos->table->forks = malloc(sizeof(pthread_mutex_t) * philos->table->n_philos);
	while (i < philos->table->n_philos)
	{
		philos[i].r_fork = philos->table->forks[philos[i].id - 1]; // id - 1 bach philo 1 ykon ando fork 0
		philos[i].l_fork = (philos->table->forks[((philos[i].id - 1) + 1) 
			% philos->table->n_philos]); // (position deyal philo + 1) % 3adad d philos
		i++;
	}
}

void    init_data(t_table *table, int ac, char **av)
{
	int i;
	t_philo *philos;

	i = 0;
	table->n_philos = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		table->n_meals = ft_atol(av[5]);
	philos = malloc(sizeof(t_philo) * (table->n_philos + 1)); // kanalloci lkola philo struct deyalo
	while (i < table->n_philos)
	{
		philos[i].id = i + 1;
		philos[i].pos = i;
		philos[i].meals_eaten = 0;
		philos[i].table = table;
		i++;
	}
	philos[i].id = 1337;
	assign_forks(philos);
	mutex_init(philos);
	create_philo(philos);
}



	// /*							printing 							*/
	// printf("%d\n",table->time_to_die);
	// printf("%d\n",table->time_to_eat);
	// printf("%d\n",table->time_to_sleep);
	// if (ac == 6)
	// 	printf("n_meals:%d\n",table->n_meals);
	// i = 0;
	// while (i < table->n_philos)
	// {
	// 	printf("id:%d\n",table->philo[i].id);
	// 	printf("death flag: %s\n", table->philo[i].death_flag ? "true" : "false");
	// 	i++;
	// }