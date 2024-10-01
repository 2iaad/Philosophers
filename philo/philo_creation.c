/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 12:08:26 by zderfouf          #+#    #+#             */
/*   Updated: 2024/10/01 15:44:34 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print(t_philo *philo, char *str)
{
	long gct;

	if (philo->table->death_flag)
		return ;
	gct = get_current_time() - (long)get(philo->table->start_time, &philo->table->start_time_m);
	pthread_mutex_lock(&philo->table->print);
	printf("%ld %ld %s\n" , gct, philo->id, str);
	pthread_mutex_unlock(&philo->table->print);
}

void	*monitor(void *tmp)
{
	int		i;
	t_philo *philo;

	i = 0;
	philo = (t_philo *)tmp;
	while (i < philo->table->n_philos)
	{
		if (get_current_time() - philo[i].last_meal > philo->table->time_to_die)
		{
			print(philo, "died");
			philo->table->death_flag = true;
			// set(&philo->table->death_flag, true, &philo->table->death_m);
			return (NULL);
		}
		i++;
		if (i == philo->table->n_philos)
			i = 0;
	}
	return (NULL);
}

bool	cycle(t_philo *philo)
{
	forks_lock(philo);

	print(philo, "is eating");
	philo->last_meal = get_current_time();
	ft_usleep(philo->table->time_to_eat);
	if (philo->table->n_meals != -1) // ila kan arg lakhar kayn
		set(&philo->meals_eaten, philo->meals_eaten + 1, &philo->table->meals_eaten_m);
	if (philo->meals_eaten ==philo->table->n_meals)
		return (forks_unlock(philo), false);
	forks_unlock(philo);

	print(philo, "is sleeping");
		ft_usleep(philo->table->time_to_sleep);

	print(philo, "is thinking");
	return (true);
}

void	*routine(void *tmp)
{
	t_philo *philo;

	(1) && (philo = (t_philo *)tmp);
	if (!(philo->id % 2))
		usleep(philo->table->time_to_eat / 2);
	while (!get(philo->table->death_flag, &philo->table->death_m))
	{
		if (!cycle(philo))
			return (NULL);
	}
	return (NULL);
}


void    create_philo(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->table->n_philos)
    {
        pthread_create(&philo[i].th, NULL, &routine, &philo[i]);
        i++;
    }
	pthread_create(&philo->table->guard, NULL, &monitor, philo);
    i = 0;
    while (i < philo->table->n_philos)
    {
        pthread_join(philo[i].th, NULL);
        i++;
    }
	pthread_join(philo->table->guard, NULL);
	mutex_destroy(philo);
}
