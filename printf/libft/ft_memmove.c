/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:11:56 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/27 13:33:53 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			p;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	p = 0;
	if (!src && !dest)
		return (NULL);
	if (s < d)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (p < n)
		{
			d[p] = s[p];
			p++;
		}
	}
	return (dest);
}

/*int	main()
{
	char	a[5] = "hola";
	char	b[5] = "adeu";
	printf("%s", a);
	printf("%s", b);
	ft_memmove(b + 2, a, 2);
	printf("%s", a);
	printf("%s", b);
}*/
