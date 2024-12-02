/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:44:19 by lbellmas          #+#    #+#             */
/*   Updated: 2024/11/27 11:45:21 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

int	ft_printf(const char *fmt, ...)
{
	int		plus;
	int		len;
	va_list	args;

	len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		plus = -1;
		if (*fmt != '%')
			plus = ft_putchar(*fmt++);
		else
		{
			if (++fmt && *fmt != '\0')
			{
				plus = ft_special((char **)&fmt, &args);
				fmt++;
			}
		}
		if (plus == -1)
			len = 0;
		len += plus;
	}
	va_end (args);
	return (len);
}

int	ft_putchar(char c)
{
	if (write (1, &c, 1))
		return (1);
	return (-1);
}

char	*ft_normal(int c, va_list *arg)
{
	char	*str;

	str = "%";
	if (c == 'c')
		str = ft_chardup(str, va_arg(*arg, int));
	else if (c == 's')
		str = (ft_prints(va_arg(*arg, char *)));
	else if (c == 'p')
		str = (ft_printp(va_arg(*arg, unsigned long)));
	else if (c == 'd' || c == 'i')
		str = (ft_printd(va_arg(*arg, int)));
	else if (c == 'u')
		str = (ft_printu(va_arg(*arg, unsigned int)));
	else if (c == 'x' || c == 'X')
		str = (ft_printx(c, va_arg(*arg, unsigned int)));
	else if (c == '%')
		str = ft_strdup("%");
	else
	{
		str = ft_strdup("%");
		if (!str)
			return (NULL);
	}
	return (str);
}
