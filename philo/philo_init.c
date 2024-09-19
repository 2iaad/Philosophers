/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:54:57 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/19 00:54:09 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	assign_forks(t_table *table)
{
	int i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->n_philos);
	while (i < table->n_philos)
	{
		table->philo[i].r_fork = table->forks[i];
		table->philo[i].l_fork = (table->forks[(table->philo[i].id - 1) % table->n_philos]);
		i++;
	}
}

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
	table->philo = malloc(sizeof(t_philo) * (table->n_philos + 1)); // kanalloci lkola philo struct deyalo
	while (i < table->n_philos) // kaninitialisi struct deyal philos
	{
		table->philo[i].id = i + 1;
		printf("{%d}\n", table->philo[i].id);
		table->philo[i].death_flag = false;
		i++;
	}
	table->philo[i].id = 1337;
	assign_forks(table);
	create_philo(table);
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