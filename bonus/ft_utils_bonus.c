/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:57:40 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/30 16:26:52 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	ft_moves_extension(char *mov, int size, t_list **a, t_list **b)
{
	if (ft_strncmp(mov, "pa", size - 1) == 0)
		ft_push_a2(a, b);
	else if (ft_strncmp(mov, "pb", size - 1) == 0)
		ft_push_b2(a, b);
	else if (ft_strncmp(mov, "ra", size - 1) == 0)
		ft_rotate_a2(a);
	else if (ft_strncmp(mov, "rb", size - 1) == 0)
		ft_rotate_b2(b);
	else if (ft_strncmp(mov, "rr", size - 1) == 0)
		ft_rotate_r2(a, b);
	else if (ft_strncmp(mov, "rra", size - 1) == 0)
		ft_rev_rotate_a2(a);
	else if (ft_strncmp(mov, "rrb", size - 1) == 0)
		ft_rev_rotate_b2(b);
	else if (ft_strncmp(mov, "rrr", size - 1) == 0)
		ft_rev_rotate_r2(a, b);
	else if (ft_strncmp(mov, "sa", size - 1) == 0)
		ft_swap_a2(a);
	else if (ft_strncmp(mov, "sb", size - 1) == 0)
		ft_swap_b2(b);
	else if (ft_strncmp(mov, "ss", size - 1) == 0)
		ft_swap_s2(a, b);
	else
		return (-1);
	return (0);
}

int	ft_moves(t_list **a, t_list **b)
{
	char	*mov;

	mov = get_next_line(0);
	while (mov)
	{
		if (ft_strlen(mov) < 2)
			return (-2);
		if (ft_moves_extension(mov, ft_strlen(mov), a, b) == -1)
		{
			free (mov);
			return (-2);
		}
		mov = get_next_line(0);
	}
	free (mov);
	return (0);
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
