/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:54:18 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/27 10:00:34 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	str[10];
	int		p;
	long	num;

	p = 0;
	num = n;
	if (num == 0)
		write (fd, "0", 1);
	else if (num < 0)
	{
		write (fd, "-", 1);
		num = -num;
	}
	while (num > 0)
	{
		str[p] = num % 10 + '0';
		num = num / 10;
		p++;
	}
	while (p > 0)
	{
		p--;
		write (fd, &str[p], 1);
	}
}

/*int	main()
{
	ft_putnbr_fd(-2147483648, 1);
	return (0);
}*/
