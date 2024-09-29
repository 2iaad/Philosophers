/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/29 19:22:15 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void    *death_checker(void	*philo)
{
	int i;
	t_philo *tmp;

	i = 0;
	tmp = (t_philo *)philo;
	while (1)
	{
		i = 0;
		while (i < tmp->table->n_philos)
		{
			// lock
			pthread_mutex_lock(&tmp->table->last_meal_m);
			if (get_current_time() - tmp[i].last_meal > tmp->table->time_to_die)
			{
				pthread_mutex_unlock(&tmp->table->last_meal_m);
				// unlock
				print(&tmp[i], "died");
				pthread_mutex_lock(&tmp->table->death_m);
				tmp->table->death_flag = true;
				pthread_mutex_unlock(&tmp->table->death_m);
				return (NULL);
			}
			pthread_mutex_unlock(&tmp->table->last_meal_m);
			// unlock
			i++;
		}
	}
	return (NULL);
}

void	*f(void *philo)
{
    t_philo *ptr;

	ptr = (t_philo *)philo;

	if (ptr->id % 2 == 0)
		usleep(800);

	pthread_mutex_lock(&ptr->table->death_m);
	while (!ptr->table->death_flag)
	{
		pthread_mutex_unlock(&ptr->table->death_m);
		if (!eat(ptr))
			return (NULL);
		if (!to_sleep(ptr))
			return (NULL);
		print(ptr, "is thinking");
		pthread_mutex_lock(&ptr->table->death_m);
	}
	pthread_mutex_unlock(&ptr->table->death_m);
    return (NULL);
}

void    create_philo(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->table->n_philos)
    {
        pthread_create(&philo[i].th, NULL, &f, &philo[i]);
        i++;
    }
    i = 0;
	pthread_create(&philo->table->guard, NULL, &death_checker, philo);
    while (i < philo->table->n_philos)
    {
        pthread_detach(philo[i].th);
        i++;
    }
	pthread_join(philo->table->guard, NULL);
	mutex_destroy(philo);
}
