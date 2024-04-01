/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:00:11 by zderfouf          #+#    #+#             */
/*   Updated: 2024/04/01 10:34:12 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_philo
{
    int n_philo; // also number of forks
    int time_to_die; // time li yqdr lphilo ytsna mn last meal ola last simulation deyalo
    int time_to_eat; // time li yakhod lphilo bach ysali lmakla, atkoun khasah 2 forks
    int time_to_sleep; // The time a philosopher will spend sleeping
    int meals; // hadi bayna (optional)
}   t_philo;

int     ft_atol(char *s);
void    parsing(int ac, char **av);

# endif