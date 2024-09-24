/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:56:27 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/24 17:00:24 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

/*

ps: 1 milliseconds ===== 1000 microseconds //// ---> usleep(x * 1000);

*/

void    eat(t_philo *philo)
{
	forks_lock(philo);

	if (philo->id %2 == 0)
		usleep(100);
	pthread_mutex_lock(&philo->table->write);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->table->write);
	// unlock
	print(philo, "is eating");
	ft_usleep(philo->table->time_to_eat);
	pthread_mutex_lock(&philo->table->write);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->write);

	forks_unlock(philo);
}

void    to_sleep(t_philo *philo)
{
    print(philo, "is sleeping");
    ft_usleep(philo->table->time_to_sleep);
}

