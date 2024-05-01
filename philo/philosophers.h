/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:00:11 by zderfouf          #+#    #+#             */
/*   Updated: 2024/05/01 01:54:59 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <sys/_pthread/_pthread_mutex_t.h>
#include <time.h>
#include <stdio.h>
#include <pthread.h> // contain all functions that control threads and mutexes
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_philo
{
    int id;
    int last_meal; // time passed from last meal
    bool death_flag;
    pthread_mutex_t r_fork;
    pthread_mutex_t l_fork;
    pthread_t th;
}   t_philo;

typedef struct s_table
<%
    int n_philos; // also number of forks
    int time_to_die; // time li yqdr lphilo ytsna mn last meal ola last simulation deyalo
    int time_to_eat; // time li yakhod lphilo bach ysali lmakla, atkoun khasah 2 forks
    int time_to_sleep; // The time a philosopher will spend sleeping
    int n_meals; // hadi bayna (optional)
    struct timeval tod;
    int     *forks;
    t_philo *philo;
%>      t_table;

int     ft_atol(char *s);
void    parsing(int ac, char **av, t_table *table);
void    init_data(t_table *table, int ac, char **av);
void    create_philo(t_table *table);

/*         ACTIONS           */

void    die(t_table *table);
void    eat(t_table *table);
void    to_sleep(t_table *table);
void    think(t_table *table);

# endif