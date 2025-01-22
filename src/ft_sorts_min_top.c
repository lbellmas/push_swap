/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_min_top.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:33:18 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/21 16:46:41 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/push_swap.h"

int	ft_is_revsorted_rev(t_list *list, int size)
{
	int	p;
	p = 0;
	t_list	*temp;
	t_list	*prev;
	if (ft_count_list(list) < 3)
		return (0);
	temp = ft_last_list(list);
	prev = ft_prev(temp, list);
	while (p < size && temp != list)
	{
		if (*(int *)temp->content > *(int *)prev->content)
			return (0);
		temp = ft_prev(temp, list);
		prev = ft_prev(prev, list);
		p++;
	}
	return (1);
}

static void	ft_min_top_4(t_list **a, t_list **b)
{
	if (*(int *)(*b)->content == 4 || *(int *)(*b)->next->content == 4)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
	}
	else
	{
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		if(*(int *)(*b)->content == 4)
			ft_push_a(a, b);
		else
		{
			ft_rev_rotate_b(b);
			ft_push_a(a, b);
		}	
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
}
static void	ft_min_top_3(t_list **a, t_list **b)
{
	if (*(int *)(*b)->content == 3)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);;
	}
	else if  (*(int *)(*b)->next->content == 3)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
	{
		ft_push_a(a, b);
		ft_check_swap(NULL, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);

	}
}

static void	ft_lonely_min_four(t_list **a, t_list **b)
{
	if (*(int *)(*b)->next->next->next->content == 4)
		ft_rev_rotate_b(b);
	else if (*(int *)(*b)->next->next->content == 4)
	{
		ft_rev_rotate_b(b);
		ft_rev_rotate_b(b);
	}
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
}

static void ft_lonely_min_three(t_list **a, t_list **b)
{
	if (*(int *)(*b)->next->next->content == 3)
		ft_rev_rotate_b(b);
	else if (*(int *)(*b)->next->content == 3)
		ft_rotate_b(b);
	ft_push_a(a, b);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
	ft_push_a(a, b);
	ft_check_swap(a, NULL);
}

void	ft_min_lonely_sort(t_list **a, t_list **b, t_chunk *chunk)
{
	if (chunk->size_min == 4)
		ft_lonely_min_four(a, b);
	else if (chunk->size_min == 3)
		ft_lonely_min_three(a, b);
	else if (chunk->size_min == 2)
	{
		ft_check_swap(NULL, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else
		ft_push_a(a, b);
}

static void	ft_sorted_min_one(t_list **a, t_list **b, int size)
{
	if (size == 2)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else if (size == 3)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else if(size == 4)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
}

void	ft_min_is_top(t_list **a, t_list **b, t_chunk *chunk)
{
	if (ft_is_revsorted(*b, chunk->size_min) == 1)
		ft_sorted_min_one(a, b, chunk->size_min);
	else if (ft_lonely(chunk->min, chunk->size_min, *b) == 1)
		ft_min_lonely_sort(a, b, chunk);
	else if (chunk->size_min == 2)
	{
		ft_check_swap(NULL, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else if(chunk->size_min == 3)
		ft_min_top_3(a, b);
	else 
	{

		if (*(int *)(*b)->content == 4 || *(int *)(*b)->next->content == 4)
		{
			ft_push_a(a, b);
			ft_push_a(a, b);
			ft_check_swap(a, b);
			ft_push_a(a, b);
			ft_check_swap(a, b);
			ft_push_a(a, b);
		}
		else
			ft_min_top_4(a, b);
	}
}
