/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:23:06 by lbellmas          #+#    #+#             */
/*   Updated: 2024/10/02 11:34:46 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(const char *s1, unsigned char *set)
{
	size_t	start;
	int		p;

	start = 0;
	while (s1[start] != '\0')
	{
		p = 0;
		while (set[p] != '\0')
		{
			if (s1[start] == set[p])
			{
				start++;
				p = 0;
			}
			else
				p++;
		}
		if (set[p] == '\0')
			break ;
	}
	return (start);
}

static size_t	ft_end(const char *s1, unsigned char *set)
{
	size_t	end;
	int		p;

	end = ft_strlen(s1) - 1;
	while (end > 0)
	{
		p = 0;
		while (set[p] != '\0')
		{
			if (s1[end] == set[p])
			{
				end--;
				break ;
			}
			else
				p++;
		}
		if (set[p] == '\0')
			break ;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		p;
	size_t	start;
	size_t	end;

	p = 0;
	if (!s1)
		return (NULL);
	else if (!set || s1[0] == '\0')
		return (ft_strdup(s1));
	start = ft_start(s1, (unsigned char *)set);
	end = ft_end(s1, (unsigned char *)set);
	if (end < start)
		return (ft_strdup(""));
	str = (char *)malloc(end - start + 2);
	if (!str)
		return (NULL);
	while (start <= end)
	{
		str[p] = s1[start];
		p++;
		start++;
	}
	str[p] = '\0';
	return (str);
}

/*int	main()
{
	printf("%s", ft_strtrim("\t ", "\t "));
	return (0);
}*/
