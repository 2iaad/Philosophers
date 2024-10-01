/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zderfouf <zderfouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:07:46 by zderfouf          #+#    #+#             */
/*   Updated: 2024/10/01 23:15:19 by zderfouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool 	numbers_check(char **av)
{
	int i;
	int j;

	i = -1;
	while (av[++i])
	{
		if (!av[i][0]) // check if ""
			return (false);
		if(ft_atol(av[i]) < 0) // check if negative
			return(false);
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] =='+' || av[i][j] == '-') && !j) // '-' in case of -0
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
	|| ft_atol(av[1]) < 60 
	|| ft_atol(av[2]) < 60 
	|| ft_atol(av[3]) < 60)
		return (false);
	if (av[4] && ft_atol(av[4]) == 0)
		return (false);
	return (true);
}

void    parsing(int ac, char **av)
{

	if (!numbers_check(av + 1))
	{
		write(2, "Invalide argument.\n", 19);
		exit(1);
	}
	if (!valid_args_check(av + 1))
		exit(0);
}