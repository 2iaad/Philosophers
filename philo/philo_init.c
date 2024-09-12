/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:54:57 by zderfouf          #+#    #+#             */
/*   Updated: 2024/08/06 14:01:33 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	assign_forks(t_table *table)
// {
// 	int i;

// 	i = -1;
// 	table->forks = (int *) malloc(sizeof(int) * table->n_philos);
// 	while (++i < table->n_philos)
// 		table->forks[i] = i;
// 	// while (++i < table->n_philos)
// 	// {
// 	// 	table->philo[i].r_fork = table->philo[i].id;
// 	// 	table->philo[i].l_fork = (table->philo[i].id - 1) % table->n_philos;
// 	// }
// 	/* 				printing 				*/
// 	i = -1;
// 	while (++i < table->n_philos)
// 		 printf("%d----",table->forks[i]);
// 	printf("\n\n");
// }

void    init_data(t_table *table, int ac, char **av)
{
	int i;

	i = 0;
	table->n_philos = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		table->n_meals = ft_atol(av[5]);
	gettimeofday(&table->tod, NULL);
	table->philo = malloc(sizeof(t_philo) * (table->n_philos + 1));
	table->fork = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	
	while (i < table->n_philos)
	{
		table->philo[i].id = i + 1;
		table->philo[i].death_flag = false;
		i++;
	}
	table->philo[i].id = 42;
	// create_philo(table);
}





	/*							printing 							*/
	// printf("%d\n",table->time_to_die);
	// printf("%d\n",table->time_to_eat);
	// printf("%d\n",table->time_to_sleep);
	// if (ac == 6)
	// 	printf("n_meals:%d\n",table->n_meals);
	// printf("time_of_day: %d\n",table->tod.tv_usec);
	// i = 0;
	// while (i < table->n_philos)
	// {
	// 	printf("id:%d\n",table->philo[i].id);
	// 	printf("death flag: %s\n", table->philo[i].death_flag ? "true" : "false");
	// 	i++;
	// }
	// assign_forks(table);