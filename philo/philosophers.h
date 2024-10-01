/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:00:11 by zderfouf          #+#    #+#             */
/*   Updated: 2024/10/01 00:54:00 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <time.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h> // contain all functions that control threads and mutexes
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_philo
{
	pthread_t		th;
	long			id;
	long			meals_eaten;
	long			last_meal;
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
	long			n_meals;
	long			death_flag;
	pthread_mutex_t	print;
	pthread_mutex_t	time_to_eat_m;
	pthread_mutex_t	meals_eaten_m;
	pthread_mutex_t	last_meal_m;
	pthread_mutex_t	time_to_sleep_m;
	pthread_mutex_t	n_meals_m;
	pthread_mutex_t	death_m;
	pthread_mutex_t	*forks;
}		t_table;

int		ft_atol(char *s);
void	print(t_philo *philo, char *str);
long	get_current_time(void);
int		ft_usleep(long milliseconds);
void	*get(long	var, pthread_mutex_t *lock);
void	set(long	*var, long new_value, pthread_mutex_t *lock);

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