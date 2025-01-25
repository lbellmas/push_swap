/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:37:41 by lbellmas          #+#    #+#             */
/*   Updated: 2024/12/20 16:03:06 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_error(char **args)
{
	int	p;
	int	c;

	p = 1;
	while (args[p])
	{
		c = p + 1;
		if (ft_error_num(args[p]) == -1)
			return (-1);
		while (args[c])
		{
			if (ft_strlen(args[p]) > ft_strlen(args[c]))
			{
				if (ft_strncmp(args[p], args[c], ft_strlen(args[p])) == 0)
					return (-1);
			}
			else
			{
				if (ft_strncmp(args[p], args[c], ft_strlen(args[c])) == 0)
					return (-1);
			}
			c++;
		}
		p++;
	}
	return (0);
}

int	ft_error_num(char *arg)
{
	int	p;

	p = 0;
	if ((arg[p] >= '0' && arg[p] <= '9') ||
			(arg[p] == '-' && (arg[p++] >= '0' && arg[p] <= '9')))
	{
		while ((arg[p] >= '0' && arg[p] <= '9'))
		{
			p++;
		}
		if (arg[p] == '\0')
			return (0);
	}
	return (-1);
}
