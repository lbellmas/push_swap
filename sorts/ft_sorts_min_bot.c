/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts_min_bot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:53:03 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/23 16:28:15 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_is_revsorted(t_list *list, int size)
{
	int	p;
	p = 0;
	t_list	*temp;
	t_list	*prev;
	if (ft_count_list(list) < 3)
		return (0);
	temp = list->next;
	prev = list;
	while (p < size && temp)
	{
		if (*(int *)temp->content > *(int *)prev->content)
			return (0);
		temp = temp->next;
		prev = prev->next;
		p++;
	}
	return (1);
}

static	int ft_min_on_top(t_list **b, t_chunk *chunk)
{
	int	i;
	int	res;
	t_list	*head;

	i = 0;
	res = 0;
	head = *b;
	while (chunk->size_min >= i)
	{
		if (chunk->min == head)
		{
			res = 1;
			break ;
		}
		i++;
		if (!(head->next))
			break;
		head = head->next;
	}
	return (res);
}

static void	ft_sort_min_4(t_list **b, t_list **a)
{
	ft_rev_rotate_b(b);
	ft_rev_rotate_b(b);
	if (*(int *)(*b)->content == 4 || *(int *)(*b)->next->content == 4)
	{
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		ft_rev_rotate_b(b);
		ft_check_swap(a, b);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
		ft_push_a(a, b);
		ft_check_swap(a, NULL);
	}
	else
	{
		ft_push_a(a, b);
		ft_rev_rotate_b(b);
		if (*(int *)(*b)->content == 4)
		{
			ft_push_a(a, b);
			ft_rev_rotate_b(b);
			ft_check_swap(a, b);
			ft_push_a(a, b);
			ft_check_swap(a, NULL);
			ft_push_a(a, b);
			ft_check_swap(a, NULL);
		}
		else
		{
			ft_rev_rotate_b(b);
			ft_push_a(a, b);
			ft_check_swap(a, b);
			ft_push_a(a, b);
			ft_check_swap(a, NULL);
			ft_push_a(a, b);
			ft_check_swap(a, NULL);
		}

	}
}

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

void	ft_sorted_bot_min(t_list **a,t_list **b, int size)
{
	ft_rev_rotate_b(b);
	if (size == 2)
	{
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else if (size == 3)
	{
		ft_rev_rotate_b(b);
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
	else if(size == 4)
	{
		ft_rev_rotate_b(b);
		ft_rev_rotate_b(b);
		ft_rev_rotate_b(b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
		ft_push_a(a, b);
	}
}

void	ft_sort_min(t_list **b, t_list **a, t_chunk *chunk)
{
	if (ft_min_on_top(b, chunk) == 1)
	{
		ft_min_is_top(a, b, chunk);
		return ;
	}
	else if (ft_is_revsorted_rev(*b, chunk->size_min) == 1)
		ft_sorted_bot_min(a, b, chunk->size_min);
	else if (chunk->size_min == 4)
	{
		ft_sort_min_4(b, a);
		return ;
	}
	else if (chunk->size_min == 3)
	{
		ft_rev_rotate_b(b);
		if (*(int *)(*b)->content == 3)
		{
			ft_push_a(a, b);
			ft_rev_rotate_b(b);
			ft_push_a(a, b);
			ft_rev_rotate_b(b);
			ft_push_a(a, b);
			ft_check_swap(a, NULL);
			return ;
		}
		ft_rev_rotate_b(b);
		if (*(int *)(*b)->content == 3)
		{
			ft_push_a(a, b);
			ft_rev_rotate_b(b);
			ft_check_swap(NULL, b);
			ft_push_a(a, b);
			ft_push_a(a, b);
		}
		else if (*(int *)(*b)->content != 3)
		{
			ft_rev_rotate_b(b);
			ft_push_a(a, b);
			ft_check_swap(NULL, b);
			ft_push_a(a, b);
			ft_push_a(a, b);
		}
	}
	else
		ft_sort_min_2(b, a, chunk);
}
