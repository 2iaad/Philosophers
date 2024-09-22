/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/22 22:55:46 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

void    *death_checker(void	*philo)
{
	t_philo *tmp;
	int i = 0;

	tmp = (t_philo *)philo;
	while (1)
	{
		if (get_current_time() - tmp->last_meal > tmp->table->time_to_die) // hna kanchecki 3la wach chi philo starva ola la
		{	
			printf("DEAD");
			break ;
		}
		i = 0;
		while (i < tmp->table->n_meals)
		{
			if (tmp[i].death_flag)
				printf("DEAD");
			i++;
		}
	}
	return (NULL);
}
// fun katprinti bla data race

void	*f(void *philo)
{
	int i;
    t_philo *tmp;

	i = 0;
	tmp = (t_philo *)philo;
	while (1)
	{
		eat(tmp);
		to_sleep(tmp);
		print(tmp, "is thinking");
		if (tmp->meals_eaten >= tmp->table->n_meals)
			break ;
	}
    return (NULL);
}

void    create_philo(t_philo *philo)
{
    int i;

    i = 0;
	// pthread_create(&philo->table->guard, NULL, &death_checker, philo);
    while (philo[i].id != 1337)
    {
        pthread_create(&philo[i].th, NULL, &f, &philo[i]);
        i++;
    }
    i = 0;
    while (philo[i].id != 1337)
    {
        pthread_join(philo[i].th, NULL);
        i++;
    }
	// pthread_join(philo->table->guard, NULL);
	mutex_destroy(philo);
}
