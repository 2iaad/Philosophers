/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:56:27 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/21 17:06:48 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/* i will be creating the eating-sleeping-thinking function using usleep to specify the 
time needed to eat sleep and think -------> in milliseconds 

ps: 1 milliseconds ===== 1000 microseconds //// ---> usleep(x * 1000);

*/



void    eat(t_philo *philo)
{
	// mutex_lock(philo);	
	printf("%ld %d is eating\n",get_current_time(), philo[0].id);
	// mutex_unlock(philo);
	ft_usleep(philo->table->time_to_eat);
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


// void    *die_checker(void	*table)
// {
// 	t_table *tmp;
// 	int i = 0;

// 	tmp = (t_table *)table;
// 	while (tmp->philo[i].id != 42)
// 	{
// 		if (tmp->philo->death_flag)
// 			printf("%d %d died\n",tmp->tod.tv_usec, tmp->philo->id);
// 		i++;
// 	}
// 	return (NULL);
// }
