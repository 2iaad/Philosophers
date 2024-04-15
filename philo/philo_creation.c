/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/04/14 15:54:40 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *f(void *philo)
{
    // int a = ((t_philo *)philo)->i;
    // printf("%d\n", a);
    printf("im a thread %d\n", *(int *)philo);
    return (NULL);
}

void    create_philo(t_philo *philo)
{
    int i;
    pthread_t th[philo->n_philo];
 
    i = 0;
    // philo->i = 1;
    while (i < philo->n_philo)
    {
        philo->i = i;
        pthread_create(&th[i], NULL, &f, &philo->i);
        i++;
    }
    i = 0;
    while (i < philo->n_philo)
    {
        pthread_join(th[i], NULL);
        i++;
    }
}
