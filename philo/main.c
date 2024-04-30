/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 06:59:47 by zderfouf          #+#    #+#             */
/*   Updated: 2024/04/22 21:14:57 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void fff()
{
    system("leaks philo");
}

int main(int ac, char **av)
{
    t_table *table;

    table = malloc (sizeof(t_table));
    if (ac == 5 || ac == 6)
    {
        parsing(ac, av, table);
        init_data(table, ac, av);

        // printf("%d\n",table->n_table);
        // printf("%d\n",table->forks);
        // printf("%d\n",table->time_to_die);
        // printf("%d\n",table->time_to_eat);
        // printf("%d\n",table->time_to_sleep);
    }
    else
        printf("Wrong number of arguments\n");
}
