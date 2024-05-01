/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 06:59:47 by zderfouf          #+#    #+#             */
/*   Updated: 2024/05/01 02:14:24 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void fff()
{
    system("leaks philo");
}

/*      time to create the philos       */

int main(int ac, char **av)
{
    t_table *table;

    table = malloc (sizeof(t_table));
    if (ac == 5 || ac == 6)
    {
        parsing(ac, av, table);
        init_data(table, ac, av);
        // create_philo(table);

    }
    else
        printf("Wrong number of arguments\n");
}
