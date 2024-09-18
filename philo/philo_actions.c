/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:56:27 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/18 15:59:03 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* i will be creating the eating-sleeping-thinking function using usleep to specify the 
time needed to eat sleep and think -------> in milliseconds 

ps: 1 milliseconds ===== 1000 microseconds //// ---> usleep(x * 1000);

*/



// void    eat(t_table *table)
// {
//     // philo->flag = true;
//     if (philo->forks >= 2)
//     {
//         printf("%d %d has taken a fork\n",philo->time.tv_usec, philo->i);
//         philo->forks -= 2;
//         printf("%d %d is eating\n",philo->time.tv_usec, philo->i);
//         while (usleep(philo->time_to_eat * 1000))
//             ;
//     }
// }

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
