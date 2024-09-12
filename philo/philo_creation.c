/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/07/31 14:51:10 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *f(void *philo)
{
    // t_table *tmp;
    
    // tmp = (t_table *)philo;
    // pthread_mutex_lock(&tmp->mutex);

//     eat(tmp);
    // think(tmp);
    // to_sleep(tmp);
    // die(tmp);
    // tmp->i++;

    // pthread_mutex_unlock(&tmp->mutex);
    return (NULL);
}

void    create_philo(t_table *table)
{
    int i;

    i = 0;
    // pthread_mutex_init(&philo->mutex, NULL);
    while (table->philo[i].id != 42)
    {
        pthread_create(&table->philo[i].th, NULL, &f, table);
        i++;
    }
    i = 0;
    while (table->philo[i].id != 42)
    {
        pthread_join(table->philo[i].th, NULL);
        i++;
    }
    // pthread_mutex_destroy(&philo->mutex);
}
