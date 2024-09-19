/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/19 00:53:02 by zderfouf         ###   ########.fr       */
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

void *f(void *table)
{
	static int a;
    t_table *tmp;
    
    tmp = (t_table *)table;
	mutex_lock(&tmp->philo[a]);

/*
		hna fin khasni neati spagetti dzp
*/
	printf("im thread number:{%d}\n", tmp->philo[a].id);
	a++;

    mutex_unlock(&tmp->philo[a]);
    return (NULL);
}

void    create_philo(t_table *table)
{
    int i;

    i = 0;
	mutex_init(table);
	printf("\n\n");
    while (table->philo[i].id != 1337)
    {
        pthread_create(&table->philo[i].th, NULL, &f, table);
        i++;
    }
    i = 0;
    while (table->philo[i].id != 1337)
    {
        pthread_join(table->philo[i].th, NULL);
        i++;
    }
	mutex_destroy(table);
}
