/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:10:50 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/25 09:34:29 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 64 && c < 91)
		|| (c > 96 && c < 123)
		|| (c > 47 && c < 58))
		return (1);
	else
		return (0);
}

/*int	main()
{
	int	a = ft_isalnum("holAAA78.9a");
	printf("%i", a);
}*/
