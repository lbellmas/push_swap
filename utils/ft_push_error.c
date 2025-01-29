/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:37:41 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/28 11:36:19 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_error(char **args)
{
	int	p;
	int	c;

	p = 0;
	while (args[++p])
	{
		c = 1;
		if (ft_error_num(args[p]) == -1)
			return (-1);
		while (args[c])
		{
			if (c != p && ft_atoi(args[p]) == ft_atoi(args[c]))
				return (-1);
			c++;
		}
	}
	return (0);
}

int	ft_error_num(char *arg)
{
	int	p;

	p = 0;
	if ((arg[p] >= '0' && arg[p] <= '9')
		|| (arg[p] == '-' && (arg[p + 1] >= '0' && arg[p] <= '9')))
	{
		if (arg[p] == '-' && (arg[p + 1] >= '0' && arg[p] <= '9'))
			p++;
		while ((arg[p] >= '0' && arg[p] <= '9'))
			p++;
		if (arg[p] == '\0')
			return (0);
	}
	return (-1);
}
