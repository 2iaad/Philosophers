/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:56:27 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/19 23:17:30 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* i will be creating the eating-sleeping-thinking function using usleep to specify the 
time needed to eat sleep and think -------> in milliseconds 

ps: 1 milliseconds ===== 1000 microseconds //// ---> usleep(x * 1000);

*/



void    eat(t_table *table)
{
	// mutex_lock(table->philo);
	// printf("%ld %d has taken a fork\n",get_current_time(), table->philo[0].id);

	
	// printf("%ld %d is eating\n",get_current_time(), table->philo[0].id);
	// ft_usleep(table->time_to_eat);
}

// void    think(t_table *table)
// {
//     while (usleep(philo->time_to_sleep * 1000))
//         ;
//     printf("%d %d is thinking\n",philo->time.tv_usec, philo->i);
// }

// void    to_sleep(t_table *table)
// {
//     while (usleep(philo->time_to_sleep * 1000))
//         ;
//     printf("%d %d is sleeping\n",philo->time.tv_usec, philo->i);
// }
