/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:56:27 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/29 13:38:09 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*

ps: 1 milliseconds ===== 1000 microseconds //// ---> usleep(x * 1000);

*/

bool    eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(philo->table->time_to_eat);

	forks_lock(philo);

	print(philo, "is eating");
	philo->last_meal = get_current_time();
	ft_usleep(philo->table->time_to_eat);

	philo->meals_eaten++;
	if (philo->meals_eaten == philo->table->n_meals)
		return (forks_unlock(philo), false);

	forks_unlock(philo);
	return (true);
}

bool    to_sleep(t_philo *philo)
{
	if (philo->meals_eaten == philo->table->n_meals)
		return (false);
    print(philo, "is sleeping");
    ft_usleep(philo->table->time_to_sleep);
	return (true);
}

