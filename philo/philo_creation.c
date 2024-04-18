/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/04/18 15:52:20 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <sys/time.h>

void *f(void *philo)
{
    t_philo *tmp;
    
    tmp = (t_philo *)philo;
    pthread_mutex_lock(&tmp->mutex);

    if (tmp->forks >= 2 && tmp->i % 2 != 0)
        eat(tmp);
    think(tmp);
    to_sleep(tmp);
    die(tmp);
    tmp->i++;

    pthread_mutex_unlock(&tmp->mutex);
    return (NULL);
}

void    init_data(t_philo *philo)
{
    gettimeofday(&philo->time, NULL);
    
}

void    create_philo(t_philo *philo)
{
    int i;
    pthread_t th[philo->n_philo];

    i = 0;
    philo->i = 1;
    init_data(philo);
    pthread_mutex_init(&philo->mutex, NULL);
    while (i < philo->n_philo)
    {
        pthread_create(&i[th], NULL, &f, philo);
        i++;
    }
    i = 0;
    while (i < philo->n_philo)
    {
        pthread_join(i[th], NULL);
        i++;
    }
    pthread_mutex_destroy(&philo->mutex);
}
