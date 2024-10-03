/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:07:46 by zderfouf          #+#    #+#             */
/*   Updated: 2024/10/03 10:18:23 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	numbers_check(char **av)
{
	int	i;
	int	j;

	i = -1;
	while (av[++i])
	{
		if (!av[i][0])
			return (false);
		if (ft_atol(av[i]) < 0)
			return (false);
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] == '+' || av[i][j] == '-') && !j)
				j++;
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (false);
		}
	}
	return (true);
}

bool	valid_args_check(char **av)
{
	if (ft_atol(av[0]) > 200 || ft_atol(av[0]) <= 0
		|| ft_atol(av[1]) < 60 || ft_atol(av[2]) < 60
		|| (ft_atol(av[3]) < 60 && ft_atol(av[3]) > INT_MAX))
		return (false);
	if (av[4] && ft_atol(av[4]) == 0)
		return (false);
	return (true);
}

bool	parsing(char **av)
{
	if (!numbers_check(av + 1))
		return (write(2, "Invalide argument.\n", 19), false);
	if (!valid_args_check(av + 1))
		return (false);
	return (true);
}
