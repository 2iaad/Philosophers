/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/29 15:10:10 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *death_checker(void	*philo)
{
	int i;
	t_philo *tmp;

	i = 0;
	tmp = (t_philo *)philo;
	usleep(200);
	while (1)
	{
		i = 0;
		while (i < tmp->table->n_philos)
		{
			if (get_current_time() - tmp[i].last_meal > tmp->table->time_to_die)
			{
				print(&tmp[i], "died");
				tmp->table->death_flag = true;
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

void	*f(void *philo)
{
	int		i;
    t_philo *ptr;

	ptr = (t_philo *)philo;
	while (!ptr->table->death_flag)
	{
		if (!eat(ptr))
			return (NULL);
		if (!to_sleep(ptr))
			return (NULL);
		print(ptr, "is thinking");
	}
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
	pthread_create(&philo->table->guard, NULL, &death_checker, philo);
    i = 0;
    while (i < philo->table->n_philos)
    {
        pthread_join(philo[i].th, NULL);
        i++;
    }
	pthread_join(philo->table->guard, NULL);

}
