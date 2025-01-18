/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:48:27 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/15 11:31:40 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

static void	ft_sort_two_min(t_list **a, t_list **b)
{
	ft_rev_rotate_b(b);
	if (*(int *)(*b)->content == 2)
	{
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
	}
	else
	{
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
}

static void	ft_sort_minthree(t_list **a, t_list **b)
{
	ft_rev_rotate_b(b);
	ft_push_a(a, b);
	ft_rev_rotate_b(b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	if ((*b)->next != *b)
		ft_rev_rotate_b(b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}

static	void	ft_sort_four(t_list **a)
{
	ft_swap_a(a);
	ft_rotate_a(a);
	ft_swap_a(a);
	ft_rotate_a(a);
	ft_swap_a(a);
	ft_rev_rotate_a(a);
	ft_check_swap(a, NULL);
	ft_rev_rotate_a(a);
	ft_check_swap(a, NULL);
}

static	void	ft_sortfour_min(t_list **a, t_list **b)
{
	ft_rev_rotate_b(b);
	ft_rev_rotate_b(b);
	ft_rev_rotate_b(b);
	ft_rev_rotate_b(b);
	ft_push_a(a, b);
	ft_push_a(a, b);
	ft_push_a(a, b);
	ft_push_a(a, b);
	if (*(int *)(*a)->next->next->content == 4)
	{
		if (*(int *)(*a)->next->next->next->content == 3)
		{
			ft_push_b(a, b);
			ft_push_b(a, b);
			ft_check_swap(a, b);
			ft_push_a(a, b);
			ft_push_a(a, b);
			return ;
		}
		ft_rotate_a(a);
		ft_rotate_a(a);
		ft_swap_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
	}
	else if (*(int *)(*a)->next->content == 4)
	{
		ft_push_b(a, b);
		ft_swap_a(a);
		ft_push_b(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
		ft_sort_four(a);
}

void	ft_sort_min(t_list **b, t_list **a, t_chunk *chunk)
{
	if (chunk->size_min == 2)
		ft_sort_two_min(a, b);
	else if (chunk->size_min == 4)
		ft_sortfour_min(a, b);
	else if (*(int *)chunk->min->content == 3)
		ft_sort_minthree(a, b);
	else
	{
		ft_rev_rotate_b(b);
		ft_rev_rotate_b(b);
		if (*(int *)(*b)->content == 3)
		{
			ft_push_a(a, b);
			ft_check_swap(NULL, b);
			ft_push_a(a, b);
			ft_push_a(a, b);
		}
		if (*(int *)(*b)->next->content != 3)
		{
			ft_rev_rotate_b(b);
			ft_push_a(a, b);
			ft_check_swap(NULL, b);
			ft_push_a(a, b);
		}
		else
		{
			ft_check_swap(NULL, b);
			ft_push_a(a, b);
			ft_push_a(a, b);
			ft_rev_rotate_b(b);
			ft_push_a(a, b);
			/*ft_push_a(a, b);
			ft_rev_rotate_b(b);
			ft_check_swap(NULL, b);
			ft_push_a(a, b);
			ft_check_swap(a, NULL);*/
		}
		ft_push_a(a, b);
	}
}
