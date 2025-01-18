/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_mid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:05:58 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/13 15:24:48 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_sort_midfour(t_list **a, t_list **b)
{
	ft_push_a(a, b);
	ft_rotate_b(b);
	ft_push_a(a, b);
	ft_rev_rotate_b(b);
	ft_check_swap(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}

static void	ft_sort_midfourlast(t_list **a, t_list **b)
{
	ft_push_a(a, b);
	ft_rotate_b(b);
	ft_rotate_b(b);
	ft_push_a(a, b);
	ft_rev_rotate_b(b);
	ft_rev_rotate_b(b);
	ft_check_swap(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}

static void	ft_sort_midtwo(t_list **a, t_list **b)
{
	ft_push_a(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}

static void	ft_sort_midthree(t_list **a, t_list **b)
{
	if (*(int *)(*b)->next->next->content == 3)
	{
		ft_push_a(a, b);
		ft_rotate_b(b);
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
}

void	ft_sort_mid(t_list **a, t_list **b, t_chunk *chunk)
{
	if (chunk->size_mid == 2)
		ft_sort_midtwo(a, b);
	if (chunk->size_mid == 3)
		ft_sort_midthree(a, b);
	if (chunk->size_mid == 4)
	{
		if (*(int *)(*b)->content == 4 || *(int *)(*b)->next->content == 4)
		{
			ft_push_a(a, b);
			ft_push_a(a, b);
			ft_check_swap(a, b);
			ft_push_a(a, b);
			ft_check_swap(a, NULL);
			ft_push_a(a, b);
			ft_check_swap(a, NULL);
		}
		else if (*(int *)(*b)->next->next->content == 4)
			ft_sort_midfour(a, b);
		else
			ft_sort_midfourlast(a, b);
	}
}
