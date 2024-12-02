/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:49:39 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/26 10:39:35 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			p;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	p = 0;
	if (n == 0)
		return (0);
	while (p < n - 1)
	{
		if (str1[p] != str2[p])
			return (str1[p] - str2[p]);
		p++;
	}
	return (str1[p] - str2[p]);
}

/*int	main()
{
	printf("%i", ft_memcmp("hola", "hol0", 4));
	return (0);
}*/
