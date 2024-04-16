/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:56:27 by zderfouf          #+#    #+#             */
/*   Updated: 2024/04/16 17:01:54 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* i will be creating the eating-sleeping-thinking function using usleep to specify the 
time needed to eat sleep and think -------> in milliseconds 

ps: 1 milliseconds ===== 1000 microseconds //// ---> usleep(x * 1000);

*/

void    die(t_philo *philo)
{
    while (usleep(philo->time_to_die * 1000))
        ;
}

void    eat(t_philo *philo)
{
    while (usleep(philo->time_to_eat * 1000))
        ;
}

void    to_sleep(t_philo *philo)
{
    while (usleep(philo->time_to_sleep * 1000))
        ;
}