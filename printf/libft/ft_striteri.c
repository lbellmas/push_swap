/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:45:40 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/27 13:37:37 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	p;

	p = 0;
	if (!s || !f)
		return ;
	while (s[p] != '\0')
	{
		f(p, &s[p]);
		p++;
	}
	s[p] = '\0';
}

/*void	f(unsigned int n, char *s)
{
	*s = *s - 32;
}

int	main()
{
	char a[] = "hola";
	ft_striteri(a, f);
	printf("%s", a);
	return (0);
}*/
