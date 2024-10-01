/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:54:57 by zderfouf          #+#    #+#             */
/*   Updated: 2024/10/01 15:27:04 by zderfouf         ###   ########.fr       */
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
		pthread_mutex_init(&philos->table->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < philos->table->n_philos)
	{
		philos[i].r_fork = &philos->table->forks[philos[i].id - 1]; // id - 1 bach philo 1 ykon ando fork 0
		philos[i].l_fork = &(philos->table->forks[((philos[i].id - 1) + 1) 
			% philos->table->n_philos]); // (position deyal philo + 1) % 3adad d philos
		i++;
	}
}

void	init_table(t_table *table, int ac, char **av)
{	
	set(&table->start_time, get_current_time(), &table->start_time_m);
	table->n_philos = ft_atol(av[1]);
	table->death_flag = false;
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (ac == 6)
		table->n_meals = ft_atol(av[5]);
	else
		table->n_meals = -1;
	if (table->n_philos <= 0 && table->n_philos > 200 || table->time_to_die < 0
	|| table->time_to_eat < 0 || table->time_to_sleep < 0)
		return ((void)write(2, "Invalide input\n", 26));

	pthread_mutex_init(&table->print,NULL);
	pthread_mutex_init(&table->start_time_m,NULL);
	pthread_mutex_init(&table->meals_eaten_m, NULL);
	pthread_mutex_init(&table->last_meal_m, NULL);
	pthread_mutex_init(&table->death_m,NULL);
}

void	init_data(int ac, char **av, t_philo **philos)
{
	int i;
	t_table *table;

	i = 0;
	table = malloc (sizeof(t_table));
	init_table(table, ac, av);
	*philos = malloc(sizeof(t_philo) * (table->n_philos));
	while (i < table->n_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].last_meal = get_current_time();
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].table = table;
		i++;
	}
	assign_forks(*philos);
}
