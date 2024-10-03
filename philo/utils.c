/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:56:50 by zderfouf          #+#    #+#             */
/*   Updated: 2024/10/03 11:19:06 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_mem(t_philo *philo)
{
	free(philo->table->forks);
	free(philo->table);
	free(philo);
}

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(long milliseconds, t_philo *philo)
{
	long	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
	{
		if (philo->table->death_flag)
			break ;
		usleep(100);
	}
	return (0);
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

int	ft_atol(char *s)
{
	long	nb;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	nb = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + s[i] - '0';
		if (nb > INT_MAX)
			return (-1);
		i++;
	}
	return (sign * nb);
}
