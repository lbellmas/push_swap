/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_max_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:22:16 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/22 11:41:34 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_is_sorted(t_list *list, int size)
{
	int p;
	t_list	*temp;
	t_list	*prev;
	p = 0;
	if (ft_count_list(list) < 3)
		return (0);
	temp = list->next;
	prev = list;
	while (p < size && temp != list)
	{
		if (*(int *)temp < *(int *)prev)
			return (0);
		temp = temp->next;
		prev = prev->next;
		p++;
	}
	return (1);
}

static void	ft_lonely_max_sort_four_ft_push_art2(t_list **a, t_list **b)
{
	if (*(int *)(*a)->content == 4 || *(int *)(*a)->next->content == 4)
	{
		if (*(int *)(*a)->next->content == 4)
			ft_swap_a(a);
		ft_rotate_a(a);
		ft_sort_three_top(a);
	}
	else
	{
		ft_push_b(a, b);
		ft_push_b(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
}

static void	ft_lonely_sort_max_four(t_list **a, t_list **b)
{
	if (*(int *)(*a)->next->next->next->content == 4)
		ft_sort_three_top(a);

	else if ((*(int *)(*a)->content == 1 && *(int *)(*a)->next->content == 2) || 
			(*(int *)(*a)->content == 2 && *(int *)(*a)->next->content == 1))
	{
		ft_push_b(a, b);
		ft_push_b(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		return ;
	}
	else if((*(int *)(*a)->content == 3 && *(int *)(*a)->next->content == 4) || 
			(*(int *)(*a)->content == 4 && *(int *)(*a)->next->content == 3))
	{
		if (*(int *)(*a)->content == 4)
			ft_swap_a(a);
		ft_rotate_a(a);
		ft_rotate_a(a);
		ft_check_swap(a, b);
	}
	else 
		ft_lonely_max_sort_four_ft_push_art2(a, b);
}

static void ft_lonely_max_sort(t_list **a, t_list **b, t_chunk *chunk)
{
	int	biggest;
	t_list	*last;
	t_list	*temp;

	temp = *a;
	biggest = ft_find_big(*a);
	last = ft_last_list(*a);
	if (chunk->size_max == 3)
	{
		if (ft_is_sorted(*a, chunk->size_max))
			return ;
		if (*(int *)temp->content == biggest)
			ft_rotate_a(a);
		else if (*(int *)(*a)->next->content == biggest)
			ft_rev_rotate_a(a);
		if (*(int *)(*a)->content > *(int *)(*a)->next->content)
			ft_swap_a(a);
		return ;
	}
	else
		ft_lonely_sort_max_four(a, b);
}

void ft_sort_three_top(t_list **a)
{
	if (*(int *)(*a)->next->next->content == 3)
	{
		if (*(int *)(*a)->next->content == 1)
			ft_swap_a(a);
		return ;
	}
	if (*(int *)(*a)->next->content == 3)
	{
		ft_rotate_a(a);
		ft_swap_a(a);
		ft_rev_rotate_a(a);
		if(*(int *)(*a)->content == 2)
			ft_swap_a(a);
		return ;
	}
	if (*(int *)(*a)->content == 3)
	{
		ft_swap_a(a);
		ft_rotate_a(a);
		ft_swap_a(a);
		ft_rev_rotate_a(a);
		ft_check_swap(a, NULL);
	}
}

static void	ft_sort_four(t_list **a, t_list **b)
{
	if (*(int *)(*a)->next->content == 4)
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
	{
		ft_swap_a(a);
		ft_push_b(a, b);
		ft_swap_a(a);
		ft_push_b(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
	}	ft_check_swap(a, NULL);
}

void	ft_sort_max_top(t_list **a, t_list **b, t_chunk *chunk)
{
	if (ft_is_sorted(*a, chunk->size_max) == 1)
		return ;
	if (chunk->size_max == 2)
	{
		ft_check_swap(a, NULL);
		return ;
	}
	if (ft_lonely(chunk->max, chunk->size_max, *a) == 1)
	{
		ft_lonely_max_sort(a, b, chunk);
		return ;
	}
	else
	{
		if ((*(int *)(*a)->next->next->next->content == 4) || (chunk->size_max == 3))
			ft_sort_three_top(a);
		else if (*(int *)(*a)->next->next->content == 4)
		{
			ft_push_b(a, b);
			ft_push_b(a, b);
			ft_check_swap(a, b);
			ft_push_a(a, b);
			ft_check_swap(a, NULL);
			ft_push_a(a, b);
			ft_check_swap(a, NULL);
		}
		else
			ft_sort_four(a, b);
	}
}
