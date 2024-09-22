/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 06:59:47 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/22 20:08:39 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
    t_table *table;
    t_philo *philo;

    if (ac == 5 || ac == 6)
    {
		table = malloc (sizeof(t_table));
        parsing(ac, av, table);
        philo = init_data(table, ac, av);
		create_philo(philo);
    }
    else
        printf("Wrong number of arguments\n");
}
