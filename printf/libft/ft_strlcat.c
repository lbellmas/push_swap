/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:07:26 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/27 10:05:09 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s;
	size_t	d;

	d = ft_strlen(dst);
	if (size <= d)
		return (size + ft_strlen(src));
	s = 0;
	while (src[s] != '\0' && d + s < size - 1)
	{
		dst[d + s] = src[s];
		s++;
	}
	dst[d + s] = '\0';
	return (d + ft_strlen(src));
}

/*int	main()
{
	char	d[20] = "hello";
	char	s[] = "world";
	size_t	result = ft_strlcat(d, s, 0);
	printf("string: %s\n", d);
	printf("return: %zu\n", result);
	return (0);
}*/
