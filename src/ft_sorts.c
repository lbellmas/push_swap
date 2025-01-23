/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:49:45 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/23 20:08:02 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_mid_a(t_list *mid, t_list *a)
{
	t_list *temp;

	if (a == mid)
		return (1);
	temp = a->next;
	while (temp != a)
	{
		if (temp == mid)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_small_sort(t_chunk *chunk, t_list **a, t_list **b, int flag)
{
	if (ft_mid_a(chunk->mid, *a) == 0)
	{
		if (flag == 3 && chunk->size_max != 1)
			ft_sort_max(a, b, chunk);
		else  if (flag == 2)
		{
			if (chunk->size_mid == 1)
				ft_push_a(a, b);
			else
			{
				ft_numbers(*b, chunk->size_mid);
				ft_sort_mid(a, b, chunk);
			}
		}
		else
		{
			if (chunk->size_min == 1)
			{
				ft_rev_rotate_b(b);
				ft_push_a(a, b);
				return ;
			}
			ft_sort_min(b, a, chunk);
		}
	}
	else
	{
		if (flag == 3 && chunk->size_max != 1)
			ft_sort_max(a, b, chunk);
		else if (flag == 2)
		{
			if (chunk->size_mid == 1)
				ft_rev_rotate_a(a);
			else
			{
				ft_rev_numbers(*a, chunk->size_mid);
				ft_sort_mid_bot(a, b, chunk);
			}
		}
		else
		{
			if (chunk->size_min == 1 && chunk->min == *b)
				ft_push_a(a, b);
			else if (chunk->size_min == 1)
			{
				ft_rev_rotate_b(b);
				ft_push_a(a, b);
			}
			else
				ft_sort_min(b, a, chunk);
		}
	}
}

/*void	ft_sort_three_top(t_list **a)
{
	if (*(int *)(*a)->next->next->content == 3)
	{
		if (*(int *)(*a)->content != 1)
			ft_swap_a(a);
		return ;
	}
	if (*(int *)(*a)->next->content == 3)
	{
		ft_rotate_a(a);
		ft_swap_a(a);
		ft_rev_rotate_a(a);
		if (*(int *)(*a)->content == 2)
			ft_swap_a(a);
		return ;
	}
	if (*(int *)(*a)->content == 3)
	{
		ft_swap_a(a);
		ft_rotate_a(a);
		ft_swap_a(a);
		ft_rev_rotate_a(a);
		if (*(int *)(*a)->content == 2)
			ft_swap_a(a);
	}
}*/

void	ft_check_swap(t_list **a, t_list **b)
{
	if (a && b && *(int *)(*a)->next->content < *(int *)(*a)->content
			&& *(int *)(*b)->next->content > *(int *)(*b)->content)
		ft_swap_s(a, b);
	else if (a && *(int *)(*a)->next->content < *(int *)(*a)->content)
		ft_swap_a(a);
	else if (b && *(int *)(*b)->next->content > *(int *)(*b)->content)
		ft_swap_b(b);
}

static	void	ft_sort_four(t_list **a)
{
	ft_swap_a(a);
	ft_rotate_a(a);
	ft_swap_a(a);
	ft_rotate_a(a);
	ft_swap_a(a);
	ft_rev_rotate_a(a);
	ft_rev_rotate_a(a);
	ft_sort_three_top(a);
}

void	ft_sort_top_a(t_list **a, t_list **b, int size)
{
	if (size == 2)
		ft_check_swap(a, NULL);
	else if (*(int *)(*a)->next->next->next->content == 4 || size == 3)
		ft_sort_three_top(a);
	else if (*(int *)(*a)->next->next->content == 4)
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
		ft_sort_three_top(a);
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

int	ft_prev_list(t_list *last, t_list *list)
{
	while (list->next != last)
		list = list->next;
	return (*(int *)list->content);
}

void	ft_sort_bot_a(t_list **a, t_list **b, t_chunk *chunk)
{
	if (chunk->size_max == 2)
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, b);
	}
	else if (chunk->size_max == 3)
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_sort_three_top(a);
	}
	else
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_sort_top_a(a, b, chunk->size_max);
	}
}

void	ft_sort_bot_a_mid(t_list **a, t_list **b, t_chunk *chunk)
{
	if (chunk->size_mid == 2)
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, b);
	}
	else if (chunk->size_mid == 3)
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_sort_three_top(a);
	}
	else if (*(int *)chunk->mid->content == 4 || ft_prev_list(chunk->mid, *a) == 4)
	{
		ft_rev_rotate_a(a);
		if (*(int *)(*a)->content == 1 || *(int *)(*a)->content == 2)
			ft_push_b(a, b);
		ft_rev_rotate_a(a);
		if (*(int *)(*a)->content == 1 || *(int *)(*a)->content == 2)
			ft_push_b(a, b);
		ft_rev_rotate_a(a);
		if (*(int *)(*a)->content == 1 || *(int *)(*a)->content == 2)
			ft_push_b(a, b);
		if (*(int *)(*a)->next->content == 1)
			ft_check_swap(NULL, b);
		else
			ft_check_swap(a, NULL);
		ft_rev_rotate_a(a);
		if (!(*(int *)(*a)->content == 1) || !(*(int *)(*a)->content == 2))
			ft_push_a(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
	{
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_rev_rotate_a(a);
		ft_sort_top_a(a, b, chunk->size_mid);
	}
}

void	ft_sort_max(t_list **a, t_list **b, t_chunk *chunk)
{
	if (ft_check_max(*a, chunk->max))
	{
		ft_numbers(*a, chunk->size_max);
		ft_sort_max_top(a, b, chunk);
	}
	else
	{
		ft_rev_numbers(*a, chunk->size_max);
		ft_sort_max_bot(a, b, chunk);
	}
}
