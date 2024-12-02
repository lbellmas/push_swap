/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:08:43 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/26 10:45:16 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	p;
	size_t	sp;

	if (!s)
		return (NULL);
	p = (size_t)start;
	sp = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - p))
		len = ft_strlen(s) - p;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (p < len + start)
	{
		str[sp] = s[p];
		p++;
		sp++;
	}
	str[sp] = '\0';
	return (str);
}

/*int	main()
{
	printf("%s", ft_substr("hola", 6, 4));
	return (0);
}*/
