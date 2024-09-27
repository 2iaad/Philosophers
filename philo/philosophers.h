/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:00:11 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/28 00:09:33 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <time.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

// data race in this case --> ./philo 7 120 60 60
// hang in this case --> ./philo 2 810 200 200 2
// philo kaymout fhad lcase ./philo 4 410 200 200 | grep died
// #if __STDC_VERSION__ < 201112L ||  __STDC_NO_ATOMICS__ == 1

// #error "atomics not supported!"

// #endif

typedef struct s_philo
{
	pthread_t		th;
	int				id;
	int				meals_eaten;
	_Atomic long			last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_table	*table;
}		t_philo;

typedef struct s_table
{
	pthread_t		guard;
	_Atomic long			start_time;
	_Atomic long			n_philos;
	_Atomic long	time_to_die;
	_Atomic long	time_to_eat;
	_Atomic long	time_to_sleep;
	_Atomic long	n_meals;
	_Atomic bool	death_flag;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}		t_table;

int		ft_atol(char *s);
void	print(t_philo *philo, char *str);
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);

void	assign_forks(t_philo *philos);
void	forks_lock(t_philo *philo);
void	forks_unlock(t_philo *philo);
void	mutex_destroy(t_philo *philo);

void	parsing(int ac, char **av);
void	init_data(int ac, char **av, t_philo **philo);
void	create_philo(t_philo *philo);

/*         ACTIONS           */

void	die(t_table *table);
bool	eat(t_philo *philo);
bool	to_sleep(t_philo *philo);

#endif