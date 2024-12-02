/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:49:56 by lbellmas          #+#    #+#             */
/*   Updated: 2024/11/27 14:22:38 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

int	ft_special_print(char **str, int fmt)
{
	int	check;
	int	len;
	int	p;

	p = 0;
	len = 0;
	check = 0;
	while (str && str[p])
	{
		check = (ft_mputchar(str[p], fmt));
		if (check == -1)
		{
			while (str && str[p])
			{
				ft_do_free(&str[p]);
				p++;
			}
			free(str);
			return (-1);
		}
		p++;
	}
	return (len);
}

char	*ft_reverse(char *reverse)
{
	char	*final;
	int		pr;
	int		pf;

	pf = 0;
	pr = ft_strlen(reverse);
	final = (char *)malloc(pr + 1);
	while (pr-- > 0)
	{
		final[pf] = reverse[pr];
		pf++;
	}
	final[pf] = '\0';
	free(reverse);
	return (final);
}

int	ft_mputchar(char *s, int fmt)
{
	int	p;

	p = 0;
	if (s[p] == 0 && fmt == 'c')
		write (1, &s[p], 1);
	while (s[p] != '\0')
	{
		if (!(write (1, &s[p], 1)))
			return (-1);
		p++;
	}
	ft_bzero(s, ft_strlen(s));
	ft_do_free(&s);
	return (0);
}

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_chardup(char *dst, int src)
{
	dst = (char *)malloc(2 * sizeof(char));
	dst[0] = src;
	dst[1] = '\0';
	return (dst);
}
