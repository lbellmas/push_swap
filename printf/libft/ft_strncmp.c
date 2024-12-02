/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:59:24 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/26 10:40:35 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			p;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	p = 0;
	if (n == 0)
		return (0);
	while (str1[p] != '\0' && str2[p] != '\0' && p < n - 1)
	{
		if (str1[p] != str2[p])
			return (str1[p] - str2[p]);
		p++;
	}
	return (str1[p] - str2[p]);
}

/*int	main()
{
	int	a = ft_strncmp("sdf", "asdf", 1);
	printf("%i", a);
	return (0);
}*/
