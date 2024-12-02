/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:14:06 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/26 10:59:47 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	p;

	p = 0;
	len = ft_strlen(s);
	str = (char *)malloc((len +1) * sizeof(char));
	if (!str)
		return (NULL);
	while (p < len)
	{
		str[p] = f(p, s[p]);
		p++;
	}
	str[p] = '\0';
	return (str);
}

/*char	f(unsigned int n, char c)
{
	c = c + n;
	return c;
}

int	main()
{
	printf("%s", ft_strmapi("hola", f));
}*/
