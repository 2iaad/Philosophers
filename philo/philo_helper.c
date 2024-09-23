/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:37:40 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/23 11:21:11 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	mutex_init(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->n_philos)
	{
		pthread_mutex_init(&philo->table->forks[i], NULL);
		i++;
	}
}

void	mutex_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print(philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	print(philo, "has taken a fork");
}

void	mutex_unlock(t_philo *philo)
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
}