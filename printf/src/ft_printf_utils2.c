/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:18:35 by lbellmas          #+#    #+#             */
/*   Updated: 2024/11/27 12:19:08 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

void	ft_initialize(int num[])
{
	int	len;

	len = 0;
	while (len < 8)
	{
		num[len] = 0;
		len++;
	}
}
