/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:18:02 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/25 20:18:25 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_upper_list(t_list **a, t_list **b, int p_small)
{
	while (p_small > 1)
	{
		ft_rotate_a(a);
		p_small--;
	}
	ft_push_b(a, b);
}

void ft_down_list(t_list **a, t_list **b, int p_small)
{
	int	max;

	max = ft_count_list(*a);
	while(p_small < max)
	{
		ft_rev_rotate_a(a);
		p_small++;
	}
	ft_rev_rotate_a(a);
	ft_push_b(a, b);
}

void	ft_push_all(t_list **a, t_list **b)
{
	while (*b)
		ft_push_a(a, b);
}

void	ft_end_list(t_list **a, t_list **b)
{
	int	check;
	int	smallest;

	check = 0;
	while (check != 2)
	{
		check = 0;
		smallest = ft_find_small(*a);
		if (smallest == 3)
			ft_rev_rotate_a(a);
		else if (smallest == 2)
			ft_swap_a(a);
		else
			check++;
		if ((*a)->next->next != *a &&
				*(int *)((*a)->next->content) > *(int *)((*a)->next->next->content))
			ft_rev_rotate_a(a);
		else
			check++;
	}
	ft_push_all(a, b);
}
