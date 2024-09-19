/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:37:40 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/19 00:50:45 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	mutex_init(t_table *table)
{
	int	i;

	i = 0;
	while (table->philo[i].id != 1337)
	{
		pthread_mutex_init(&table->philo->l_fork, NULL);
		pthread_mutex_init(&table->philo->r_fork, NULL);
		i++;
	}
}

void	mutex_lock(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->r_fork);
}

void	mutex_unlock(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->r_fork);
}

void	mutex_destroy(t_table *table)
{
	int	i;

	i = 0;
	while (table->philo[i].id != 1337)
	{
		pthread_mutex_destroy(&table->philo->l_fork);
		pthread_mutex_destroy(&table->philo->r_fork);
		i++;
	}
}