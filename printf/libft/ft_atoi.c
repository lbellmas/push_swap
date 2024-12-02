/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 09:39:35 by lbellmas          #+#    #+#             */
/*   Updated: 2024/11/27 14:11:49 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	p;
	int	sign;
	int	num;

	sign = 1;
	p = 0;
	num = 0;
	while (nptr[p] == 32 || (nptr[p] >= 9 && nptr[p] <= 13))
		p++;
	if (nptr[p] == '-' || nptr[p] == '+')
	{
		if (nptr[p] == '-')
			sign = -sign;
		p++;
	}
	while (nptr[p] >= '0' && nptr[p] <= '9')
	{
		num = num * 10 + (nptr[p] - '0');
		p++;
	}
	return (num * sign);
}

/*int	main()
{
	printf("%i", ft_atoi("-2147483648"));
	return (0);
}*/
