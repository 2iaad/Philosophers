/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:56:27 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/29 19:17:58 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*

ps: 1 milliseconds ===== 1000 microseconds //// ---> usleep(x * 1000);

*/

bool    eat(t_philo *philo)
{

	
	// pthread_mutex_lock(&philo->table->n_meals_m);
	// if (philo->meals_eaten == philo->table->n_meals)
	// 	return (false);
	// pthread_mutex_unlock(&philo->table->n_meals_m);

	forks_lock(philo);

	pthread_mutex_lock(&philo->table->last_meal_m);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->table->last_meal_m);
	if (philo->table->n_philos == 1)
		return 0;
	print(philo, "is eating");
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_lock(&philo->table->n_meals_m);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->n_meals_m);

	forks_unlock(philo);
	return (true);
}

bool    to_sleep(t_philo *philo)
{
	// pthread_mutex_lock(&philo->table->n_meals_m);
	// if (philo->meals_eaten == philo->table->n_meals)
	// 	return (false);
	// pthread_mutex_unlock(&philo->table->n_meals_m);
    print(philo, "is sleeping");
    ft_usleep(philo->table->time_to_sleep);
	return (true);
}

