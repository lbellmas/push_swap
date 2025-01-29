/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:57:40 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/29 16:42:31 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_moves(t_list **a, t_list **b)
{
	char	*mov;

	mov = get_next_line(0);
	while (mov)
	{
		if (ft_strlen(mov) < 2)
		{
			ft_printf("end");
			return ;
		}
		if (ft_strncmp(mov, "pa", ft_strlen(mov) - 1) == 0)
			ft_push_a2(a, b);
		else if (ft_strncmp(mov, "pb", ft_strlen(mov) - 1) == 0)
			ft_push_b2(a, b);
		else if (ft_strncmp(mov, "ra", ft_strlen(mov) - 1) == 0)
			ft_rotate_a2(a);
		else if (ft_strncmp(mov, "rb", ft_strlen(mov) - 1) == 0)
			ft_rotate_b2(b);
		else if (ft_strncmp(mov, "rr", ft_strlen(mov) - 1) == 0)
			ft_rotate_r2(a, b);
		else if (ft_strncmp(mov, "rra", ft_strlen(mov) - 1) == 0)
			ft_rev_rotate_a2(a);
		else if (ft_strncmp(mov, "rrb", ft_strlen(mov) - 1) == 0)
			ft_rev_rotate_b2(b);
		else if (ft_strncmp(mov, "rrr", ft_strlen(mov) - 1) == 0)
			ft_rev_rotate_r2(a, b);
		else if (ft_strncmp(mov, "sa", ft_strlen(mov) - 1) == 0)
			ft_swap_a2(a);
		else if (ft_strncmp(mov, "sb", ft_strlen(mov) - 1) == 0)
			ft_swap_b2(b);
		else if (ft_strncmp(mov, "ss", ft_strlen(mov) - 1) == 0)
			ft_swap_s2(a, b);
		else
			return (free (mov));
		mov = get_next_line(0);
	}
	free (mov);
}

int	ft_check(t_list **a, t_list **b)
{
	t_list	*temp;
	t_list	*prev;

	prev = *a;
	temp = (*a)->next;
	if (*b)
		return (-1);
	while (temp != *a)
	{
		if (*(int *)temp->content < *(int *)prev->content)
			return (-1);
		temp = temp->next;
		prev = prev->next;
	}
	return (0);
}
