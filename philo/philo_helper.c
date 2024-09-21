/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 00:37:40 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/21 17:08:23 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	mutex_init(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo[i].id != 1337)
	{
		pthread_mutex_init(&philo->r_fork, NULL);
		pthread_mutex_init(&philo->l_fork, NULL);
		i++;
	}
}

void	mutex_lock(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	printf("%ld %d has taken a fork\n",get_current_time(), philo[0].id);
	pthread_mutex_lock(&philo->l_fork);
	printf("%ld %d has taken a fork\n",get_current_time(), philo[0].id);
}

void	mutex_unlock(t_philo *philo)
{
	pthread_mutex_lock(&philo->r_fork);
	pthread_mutex_lock(&philo->l_fork);
	printf("%ld %d is sleeping\n",get_current_time(), philo[0].id);
	ft_usleep(sleeptime);
}

void	mutex_destroy(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo[i].id != 1337)
	{
		pthread_mutex_destroy(&philo->r_fork);
		pthread_mutex_destroy(&philo->l_fork);
		i++;
	}
}