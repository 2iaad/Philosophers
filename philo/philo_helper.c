/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:37:40 by zderfouf          #+#    #+#             */
/*   Updated: 2024/10/03 10:20:24 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_philo *philo, char *str)
{
	long	gct;

	if (philo->table->death_flag)
		return ;
	pthread_mutex_lock(&philo->table->print);
	gct = get_current_time() - (long)get(philo->table->start_time,
			&philo->table->start_time_m);
	printf("%ld %ld %s\n", gct, philo->id, str);
	if (str[0] == 'd')
		philo->table->death_flag = true;
	pthread_mutex_unlock(&philo->table->print);
}

bool	forks_lock(t_philo *philo)
{
	if (philo->table->death_flag)
		return (false);
	pthread_mutex_lock(philo->r_fork);
	print(philo, "has taken a fork");
	if (philo->table->n_philos == 1)
		return (false);
	pthread_mutex_lock(philo->l_fork);
	print(philo, "has taken a fork");
	return (true);
}

void	forks_unlock(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*get(long var, pthread_mutex_t *lock)
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
