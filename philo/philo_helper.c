/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:37:40 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/25 16:24:23 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"
#include <pthread.h>

void	forks_lock(t_philo *philo)
{
	if (philo->table->n_philos != 1)
	{
		pthread_mutex_lock(philo->r_fork);
		print(philo, "has taken a fork");
	}
	pthread_mutex_lock(philo->l_fork);
	print(philo, "has taken a fork");
}

void	forks_unlock(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	mutex_destroy(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->n_philos)
	{
		pthread_mutex_destroy(&philo->table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->table->print);
	pthread_mutex_destroy(&philo->table->last_meal_m);
	pthread_mutex_destroy(&philo->table->n_meals_m);
	pthread_mutex_destroy(&philo->table->death_m);
}

void	print(t_philo *philo, char *str)
{
	size_t gct;


	pthread_mutex_lock(&philo->table->death_m);
	pthread_mutex_lock(&philo->table->n_meals_m);
	if (philo->table->death_flag || philo->meals_eaten == philo->table->n_meals)
	{
		pthread_mutex_unlock(&philo->table->n_meals_m);
		pthread_mutex_unlock(&philo->table->death_m);
		return ;
	}
	pthread_mutex_unlock(&philo->table->n_meals_m);
	pthread_mutex_unlock(&philo->table->death_m);


	pthread_mutex_lock(&philo->table->print);
	gct = get_current_time() - philo->table->start_time;
	printf("%ld %d %s\n" , gct, philo->id, str);
	pthread_mutex_unlock(&philo->table->print);

}