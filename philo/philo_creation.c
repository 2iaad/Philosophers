/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/24 17:16:10 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *death_checker(void	*philo)
{
	t_philo *tmp;

	int i = 0;
	tmp = (t_philo *)philo;
	while (1)
	{
		i = 0;
		while (i < tmp->table->n_philos)
		{
			// lock
			pthread_mutex_lock(&tmp->table->read);
			if (get_current_time() - tmp[i].last_meal > tmp->table->time_to_die)
			{
				pthread_mutex_unlock(&tmp->table->read);
				// unlock
				print(&tmp[i], "died");
				pthread_mutex_lock(&tmp->table->write);
				tmp->table->death_flag = true;
				pthread_mutex_unlock(&tmp->table->write);
				return (NULL);
			}
			else
				pthread_mutex_unlock(&tmp->table->read);
			// unlock
			i++;
		}
	}
	return (NULL);
}

void	*f(void *philo)
{
	int i;
    t_philo *ptr;

	i = 0;
	ptr = (t_philo *)philo;
	while (!ptr->table->death_flag) //check imediatly with a mutex in the print func
	{
		eat(ptr);
		to_sleep(ptr);
		print(ptr, "is thinking");
	}
    return (NULL);
}

void    create_philo(t_philo *philo)
{
    int i;

    i = 0;
    while (philo[i].id != 1337)
    {
        pthread_create(&philo[i].th, NULL, &f, &philo[i]);
        i++;
    }
    i = 0;
	pthread_create(&philo->table->guard, NULL, &death_checker, philo);
    while (philo[i].id != 1337)
    {
        pthread_join(philo[i].th, NULL);
        i++;
    }
	pthread_join(philo->table->guard, NULL);
	mutex_destroy(philo);
}
