/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:56:27 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/23 13:27:49 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <sys/_pthread/_pthread_mutex_t.h>

/*

ps: 1 milliseconds ===== 1000 microseconds //// ---> usleep(x * 1000);

*/

void    eat(t_philo *philo)
{
	pthread_mutex_t locker;

	if (philo->id %2 == 0)
		usleep(50);

	pthread_mutex_init(&locker, NULL);
	pthread_mutex_lock(&locker);
	forks_lock(philo);
	philo->last_meal=get_current_time();
	ft_usleep(philo->table->time_to_eat);
	print(philo, "is eating");
	philo->meals_eaten++;
	printf("-------------------->{{{{{%d}}}}}\n", philo->meals_eaten);

	pthread_mutex_unlock(&locker);
	pthread_mutex_destroy(&locker);

	forks_unlock(philo);
}

void    to_sleep(t_philo *philo)
{
    ft_usleep(philo->table->time_to_sleep);
    print(philo, "is sleeping");
}
