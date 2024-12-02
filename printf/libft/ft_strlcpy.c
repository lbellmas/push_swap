/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:12:20 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/26 15:49:11 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s;

	s = 0;
	if (size > 0)
	{
		while (src[s] != '\0' && s < (size - 1))
		{
			dst[s] = src[s];
			s++;
		}
		dst[s] = '\0';
	}
	return (ft_strlen(src));
}

/*int     main()
{
        char    *s1 = "hola";
        char    *s2 = "adeu";

        printf("%zu\n", ft_strlcpy(s1, s2, 0));
        printf("Contenido de s1: %s\n", s1);
        return 0;
}*/
