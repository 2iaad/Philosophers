/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:56:27 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/23 12:00:56 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*

ps: 1 milliseconds ===== 1000 microseconds //// ---> usleep(x * 1000);

*/

void    eat(t_philo *philo)
{
	if (philo->id %2 == 0)
		usleep(50);
	mutex_lock(philo);
	ft_usleep(philo->table->time_to_eat);
	philo->last_meal=get_current_time();
	print(philo, "is eating");
	philo->meals_eaten++;
	printf("-------------------->{{{{{%d}}}}}\n", philo->meals_eaten);
	mutex_unlock(philo);
}

void    to_sleep(t_philo *philo)
{
    ft_usleep(philo->table->time_to_sleep);
    print(philo, "is sleeping");
}
