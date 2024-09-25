/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:56:50 by zderfouf          #+#    #+#             */
/*   Updated: 2024/09/25 12:17:22 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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