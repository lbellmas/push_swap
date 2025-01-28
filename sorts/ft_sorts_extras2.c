/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_extras2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:36:22 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/27 15:37:25 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_sort_min_2(t_list **b, t_list **a, t_chunk *chunk)
{
	if (ft_min_on_top(b, chunk) == 0)
		ft_rev_rotate_b(b);
	if (*(int *)(*b)->content == 1)
	{
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		return ;
	}
	else
	{
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
	}
}
