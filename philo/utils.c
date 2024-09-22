/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:56:50 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/22 23:00:08 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <sys/_pthread/_pthread_mutex_t.h>

int ft_atol(char *s)
{
    long    nb;
    int     i;
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
		i++;
	}
	return (sign * nb);
}

void	print(t_philo *philo, char *str)
{
	size_t gct;
	pthread_mutex_t locker;

	if (philo->death_flag || philo->meals_eaten == philo->table->n_meals)
		return ;

	pthread_mutex_init(&locker, NULL);
	pthread_mutex_lock(&locker);

	gct = get_current_time() - philo->table->start_time;
	printf("%ld %d %s\n" , gct, philo->id, str);

	pthread_mutex_unlock(&locker);
	pthread_mutex_destroy(&locker);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((time.tv_sec * 1000 )+ (time.tv_usec / 1000));
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(100);
	return (0);
}  