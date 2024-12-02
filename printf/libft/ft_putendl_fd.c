/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:43:21 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/20 13:53:17 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	p;

	p = 0;
	while (s[p] != '\0')
	{
		ft_putchar_fd(s[p], fd);
		p++;
	}
	write (fd, "\n", 1);
	return ;
}

/*int	main()
{
	ft_putendl_fd("hola", 1);
	return (0);
}*/
