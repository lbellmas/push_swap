/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:56:21 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/20 13:53:50 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	p;

	p = 0;
	while (s[p] != '\0')
	{
		ft_putchar_fd(s[p], fd);
		p++;
	}
	return ;
}

/*int	main()
{
	ft_putstr_fd("hola", 1);
	return (0);
}*/
