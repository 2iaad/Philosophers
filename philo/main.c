/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 06:59:47 by zderfouf          #+#    #+#             */
/*   Updated: 2024/04/14 15:17:53 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// create the thread , and join them in a loop

void fff()
{
    system("leaks philo");
}

int main(int ac, char **av)
{
    t_philo	*philo;

    // atexit(fff);
    philo = malloc (sizeof(t_philo));
    if (ac == 5 || ac == 6)
    {
        parsing(ac, av, philo);
        create_philo(philo);
    
        free(philo);
        // printf("%d\n",philo->n_philo);
        // printf("%d\n",philo->time_to_die);
        // printf("%d\n",philo->time_to_eat);
        // printf("%d\n",philo->time_to_sleep);
        // if (ac == 6)
        // 	printf("%d\n",philo->meals);
    }
    else
        printf("Wrong number of arguments\n");
}
