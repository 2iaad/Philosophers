/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:00:11 by zderfouf          #+#    #+#             */
/*   Updated: 2024/10/03 10:18:33 by zderfouf         ###   ########.fr       */
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
# include <limits.h>

typedef struct s_philo
{
	pthread_t		th;
	long			id;
	_Atomic long	meals_eaten;
	_Atomic long	last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_table	*table;
}		t_philo;

typedef struct s_table
{
	pthread_t		guard;
	long			start_time;
	long			n_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	_Atomic long	n_meals;
	_Atomic long	death_flag;
	pthread_mutex_t	print;
	pthread_mutex_t	start_time_m;
	pthread_mutex_t	meals_eaten_m;
	pthread_mutex_t	last_meal_m;
	pthread_mutex_t	death_m;
	pthread_mutex_t	*forks;
}		t_table;

int		ft_atol(char *s);
void	print(t_philo *philo, char *str);
long	get_current_time(void);
int		ft_usleep(long milliseconds, t_philo *philo);
void	*get(long var, pthread_mutex_t *lock);
void	set(long	*var, long new_value, pthread_mutex_t *lock);
void	free_mem(t_philo *philo);

void	assign_forks(t_philo *philos);
bool	forks_lock(t_philo *philo);
void	forks_unlock(t_philo *philo);
void	mutex_destroy(t_philo *philo);

bool	parsing(char **av);
bool	init_data(int ac, char **av, t_philo **philo);
void	create_philo(t_philo *philo);

/*         ACTIONS           */

void	die(t_table *table);
bool	eat(t_philo *philo);
bool	to_sleep(t_philo *philo);

#endif