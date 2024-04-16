/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/04/16 17:34:58 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <sys/time.h>

void *f(void *philo)
{
    t_philo *tmp;
    
    tmp = (t_philo *)philo;
    gettimeofday(&tmp->time, NULL);
    pthread_mutex_lock(&tmp->mutex);

    printf("%d  hello in thread number: %d!\n",tmp->time.tv_usec, tmp->i);
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
