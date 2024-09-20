/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/20 22:14:01 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*f(void *philo)
{
	int i;
    t_philo *tmp;

	i = 0;
	tmp = (t_philo *)philo;
	while (1)
	{
		eat(tmp);
		i++;
		if (tmp[i].id == 1337)
		{
			printf("\n");
			i = 0;
		}
		if (tmp[i].meals_eaten == tmp->table->n_meals || tmp[i].death_flag == true)
			break ;
	}
    return (NULL);
}

void    create_philo(t_philo *philo)
{
    int i;

    i = 0;
	mutex_init(philo);
    while (philo[i].id != 1337)
    {
        pthread_create(&philo[i].th, NULL, &f, philo);
        i++;
    }
    i = 0;
    while (philo[i].id != 1337)
    {
        pthread_join(philo[i].th, NULL);
        i++;
    }
	mutex_destroy(philo);
}
