/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cases_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:17:57 by lbellmas          #+#    #+#             */
/*   Updated: 2024/11/27 12:18:01 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

int	ft_hastag(char **str, char fmt)
{
	int	p;

	p = 0;
	while (str[p])
		p++;
	if (fmt == 'X')
		str[p] = ft_strdup("0X");
	else
		str[p] = ft_strdup("0x");
	if (!str[p])
		return (-1);
	ft_swap(&str[p], &str[p - 1]);
	return (1);
}
