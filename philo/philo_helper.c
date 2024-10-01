/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:37:40 by zderfouf          #+#    #+#             */
/*   Updated: 2024/10/01 17:38:02 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	forks_lock(t_philo *philo)
{
	if (philo->table->death_flag)
		return ;
	pthread_mutex_lock(philo->r_fork);
	print(philo, "has taken a fork");

	pthread_mutex_lock(philo->l_fork);
	print(philo, "has taken a fork");
}

void	forks_unlock(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	mutex_destroy(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->n_philos)
	{
		pthread_mutex_destroy(&philo->table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->table->print);
	pthread_mutex_destroy(&philo->table->start_time_m);
	pthread_mutex_destroy(&philo->table->meals_eaten_m);
	pthread_mutex_destroy(&philo->table->last_meal_m);
	pthread_mutex_destroy(&philo->table->death_m);
}

void	*get(long	var, pthread_mutex_t *lock)
{
	long	value;

	pthread_mutex_lock(lock);
	value = var;
	pthread_mutex_unlock(lock);

	return ((void *)value);
}

void	set(long	*var, long new_value, pthread_mutex_t *lock)
{
	pthread_mutex_lock(lock);
	*var = new_value;
	pthread_mutex_unlock(lock);
}