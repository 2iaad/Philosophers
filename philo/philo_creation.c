/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/04/16 10:28:15 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void *f(void *philo)
{
    t_philo *tmp = (t_philo *)philo;
    pthread_mutex_lock(&tmp->mutex);
    printf("hello in thread number: %d!\n",tmp->i);
    tmp->i++;
    pthread_mutex_unlock(&tmp->mutex);
    return (NULL);
}

void    create_philo(t_philo *philo)
{
    int i;
    pthread_t th[philo->n_philo];
 
    i = 0;
    philo->i = 1;
    pthread_mutex_init(&philo->mutex, NULL);
    while (i < philo->n_philo)
    {
        pthread_create(&th[i], NULL, &f, philo);
        i++;
    }
    i = 0;
    while (i < philo->n_philo)
    {
        pthread_join(th[i], NULL);
        i++;
    }
    pthread_mutex_destroy(&philo->mutex);
}
