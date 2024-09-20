/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/20 18:46:29 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void    *die_checker(void	*table)
// {
// 	t_table *tmp;
// 	int i = 0;

// 	tmp = (t_table *)table;
// 	while (tmp->philo[i].id != 42)
// 	{
// 		if (tmp->philo->death_flag)
// 			printf("%d %d died\n",tmp->tod.tv_usec, tmp->philo->id);
// 		i++;
// 	}
// 	return (NULL);
// }



void	*f(void *philo)
{
	int i;
    t_philo *tmp;

	i = 0;
	tmp = (t_philo *)philo;
	while (tmp[i].id != 1337)
	{
		printf("{%d}", tmp[i].id);
		i++;
	}
	printf("\n\n");
    return (NULL);
}

void    create_philo(t_philo *philo)
{
    int i;

    i = 0;
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
