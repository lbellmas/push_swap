/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_max_bot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:21:26 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/21 12:22:43 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_sort_max_bottom_four(t_list **a, t_list **b)
{
	ft_rev_rotate_a(a);
	ft_rev_rotate_a(a);
	ft_rev_rotate_a(a);
	ft_push_b(a, b);
	ft_rev_rotate_a(a);
	ft_push_b(a, b);
	ft_check_swap(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}

static void	ft_sort_bottom_three_max(t_list **a, t_list **b, t_chunk *chunk)
{
	if (*(int *)chunk->max->content == 3)
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
	}
	else if (ft_prev_list(chunk->max, *a) == 3)
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_swap_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
	}
	else
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_push_b(a, b);
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
}

static	void	ft_sort_four_max_a(t_list **a, t_list **b)
{
	ft_rev_rotate_a(a);
	ft_rev_rotate_a(a);
	ft_push_b(a, b);
	ft_push_b(a, b);
	ft_rev_rotate_a(a);
	ft_rev_rotate_a(a);
	ft_check_swap(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}

void	ft_sort_max_bot(t_list **a, t_list **b, t_chunk *chunk)
{
	if (chunk->size_max == 2)
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
	}
	else if (chunk->size_max == 3)
		ft_sort_bottom_three_max(a, b, chunk);
	else
	{
		if (ft_prev_list(ft_prev(ft_prev(chunk->max, *a), *a), *a) == 4
			|| ft_prev_list(ft_prev(chunk->max, *a), *a) == 4)
			ft_sort_four_max_a(a, b);
		else
			ft_sort_max_bottom_four(a, b);
	}
}
