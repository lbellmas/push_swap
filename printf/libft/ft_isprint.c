/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:11:33 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/20 15:57:41 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c < 32) || (c > 126))
		return (0);
	else
		return (1);
}

/*int	main()
{
	printf("%i", ft_isprint(65));
	return (0);
}*/
