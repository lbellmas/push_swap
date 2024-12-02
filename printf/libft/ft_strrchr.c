/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:35:06 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/26 09:59:53 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			len;

	ch = (unsigned char)c;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == ch)
			return ((char *)&s[len]);
		len--;
	}
	if (s[0] == ch)
		return ((char *)&s[0]);
	return (NULL);
}

/*int	main()
{
	char	*a = ft_strrchr("hola AsuAuTVUAu8A5", 'h');
	printf("%s", a);
	return (0);
}*/
