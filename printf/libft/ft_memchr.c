/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:25:41 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/27 12:22:38 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			p;

	str = (unsigned char *)s;
	p = 0;
	while (p < n)
	{
		if (str[p] == (unsigned char)c)
			return (&str[p]);
		p++;
	}
	return (NULL);
}

/*int	main()
{
	printf("%s", (char *)ft_memchr("0x7ffd88caf0a0", '0', 42));
	return (0);
}*/
