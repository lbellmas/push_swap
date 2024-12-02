/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:53:05 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/26 15:58:38 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	int				p;

	ch = (unsigned char)c;
	p = 0;
	while (s[p] != '\0')
	{
		if (s[p] == ch)
			return ((char *)&s[p]);
		p++;
	}
	if (ch == 0)
		return ((char *)&s[p]);
	return (NULL);
}

/*int	main()
{
	char	*o = ft_strchr("hAola Astr" + 3, 65);
	printf("%s", o);
	return (0);
}*/
