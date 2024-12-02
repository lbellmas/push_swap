/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calculate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:51:50 by lbellmas          #+#    #+#             */
/*   Updated: 2024/11/28 11:06:24 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

int	ft_calculate(int *flag, char fmt, int len, char *str)
{
	if (flag[3] != 0 && flag[3] < len && (fmt == 's'))
	{
		len = ft_strlcpy(str, str, flag[3] + 1);
		len = flag[3];
		flag[3] = 0;
	}
	else if (flag[3] > 0)
		len = ft_dot_calculate(flag, fmt, len, str);
	if (flag[4] || flag[5] || flag[6])
		len += ft_pmh_calculate(flag, fmt, str);
	if (fmt == 'p' && str[0] != '(')
	{
		flag[4] = 1;
		len += 2;
	}
	if (flag[0])
		ft_num_calculate(flag, fmt, len);
	if (flag[2])
		len += ft_zero_calculate(flag, fmt, len, str);
	if (flag[1])
		ft_minus_calculate(flag, len);
	len = len + flag[0] + flag[1] + flag[2];
	if (flag[7] && len == (int)ft_strlen(str))
		len = 0;
	return (len);
}
