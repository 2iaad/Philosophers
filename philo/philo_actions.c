/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:56:27 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/23 18:07:42 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*

ps: 1 milliseconds ===== 1000 microseconds //// ---> usleep(x * 1000);

*/

void    eat(t_philo *philo)
{
	pthread_mutex_t locker;

	if (philo->id %2 == 0)
		usleep(100);

	forks_lock(philo);
	pthread_mutex_init(&locker, NULL);
	pthread_mutex_lock(&locker);
	philo->last_meal = get_current_time();
	print(philo, "is eating");
	ft_usleep(philo->table->time_to_eat);
	philo->meals_eaten++;
	// printf("-------------------->{{{{{%d}}}}}\n", philo->meals_eaten);

	pthread_mutex_unlock(&locker);
	pthread_mutex_destroy(&locker);

	forks_unlock(philo);
}

void    to_sleep(t_philo *philo)
{
    print(philo, "is sleeping");
    ft_usleep(philo->table->time_to_sleep);
}
