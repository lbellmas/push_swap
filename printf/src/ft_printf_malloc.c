/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:56:46 by lbellmas          #+#    #+#             */
/*   Updated: 2024/11/27 11:22:00 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"
#include "../libft/libft.h"

int	ft_malloc_count(int *flag)
{
	int	p;
	int	len;

	len = 1;
	p = 0;
	while (p < 7)
	{
		if (flag[p])
			len++;
		p++;
	}
	return (len);
}

char	**ft_malloc(char **str, int *flag)
{
	int		p;
	char	**dst;

	p = 1;
	dst = (char **)malloc((ft_malloc_count(flag) + 1) * sizeof(char *));
	if (flag[7] == 1 && !flag[0] && !flag[1] && !flag[2]
		&& !flag[3] && !flag[4] && !flag[5] && !flag[6])
		dst[0] = ft_strdup("");
	else
		dst[0] = ft_strdup(*str);
	if (flag[7] == 1 && (flag[0] || flag[1] || flag[2]
			|| flag[3] || flag[4] || flag[5] || flag[6]))
		ft_memset(*dst, ' ', ft_strlen(*str));
	while (p <= ft_malloc_count(flag))
	{
		dst[p] = NULL;
		p++;
	}
	ft_do_free(str);
	return (dst);
}

void	ft_do_free(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
