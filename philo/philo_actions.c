/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:56:27 by zderfouf          #+#    #+#             */
/*   Updated: 2024/07/31 14:51:59 by zderfouf         ###   ########.fr       */
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
    printf("%d %d died\n",philo->time.tv_usec, philo->i);
}

void    eat(t_philo *philo)
{
    // philo->flag = true;
    if (philo->forks >= 2)
    {
        printf("%d %d has taken a fork\n",philo->time.tv_usec, philo->i);
        philo->forks -= 2;
        printf("%d %d is eating\n",philo->time.tv_usec, philo->i);
        while (usleep(philo->time_to_eat * 1000))
            ;
    }
}

void    think(t_philo *philo)
{
    while (usleep(philo->time_to_sleep * 1000))
        ;
    printf("%d %d is thinking\n",philo->time.tv_usec, philo->i);
}

void    to_sleep(t_philo *philo)
{
    while (usleep(philo->time_to_sleep * 1000))
        ;
    printf("%d %d is sleeping\n",philo->time.tv_usec, philo->i);
}
