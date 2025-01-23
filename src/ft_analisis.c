/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analisis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:57:41 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/23 20:13:55 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_count_list(t_list *a)
{
	t_list	*temp;
	int	count;

	temp = a;
	count = 1;
	if (!a)
		return (0);
	while (temp->next != a)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	ft_mid_list(int n_list)
{
	int	mid;

	if (n_list % 2 != 0)
		n_list++;
	mid = n_list / 2;
	return (mid);
}

int	ft_find_small(t_list *a)
{
	t_list	*temp;
	t_list	*small;
	int	n_small;
	int	count;

	count = 1;
	n_small = *(int *)a->content;
	small = a;
	temp = a->next;
	while (temp != a)
	{
		if (n_small > *(int *)temp->content)
		{
			n_small = *(int *)temp->content;
			small = temp;
		}
		temp = temp->next;
	}
	while (a != small)
	{
		count++;
		a = a->next;
	}
	return (count);
}

int	ft_find_big(t_list *a)
{
	t_list	*temp;
	t_list	*big;
	int	n_big;
	int	count;

	count = 1;
	n_big = *(int *)a->content;
	big = a;
	temp = a->next;
	while (temp != a)
	{
		if (n_big < *(int *)temp->content)
		{
			n_big = *(int *)temp->content;
			big = temp;
		}
		temp = temp->next;
	}
	while (a != big)
	{
		count++;
		a = a->next;
	}
	return (count);
}

int	ft_find_smaller(t_list *a, int n_push)
{
	t_list	*temp;
	t_list	*smaller;
	int	n_smaller;
	int	count;

	count = 1;
	temp = a;
	while (n_push < *(int *)temp->content)
	{
		temp = temp->next;
		if (temp == a)
			return (0);
	}
	smaller = temp;
	n_smaller = *(int *)temp->content;
	temp = temp->next;
	while (temp != a)
	{
		if (n_smaller < *(int *)temp->content && *(int *)temp->content < n_push)
		{
			n_smaller = *(int *)temp->content;
			smaller = temp;
		}
		temp = temp->next;
	}
	while (a != smaller)
	{
		count++;
		a = a->next;
	}
	return (count);
}

int	ft_find_bigger(t_list *a, int n_push)
{
	t_list	*temp;
	t_list	*bigger;
	int	n_bigger;
	int	count;

	count = 1;
	temp = a;
	while (n_push > *(int *)temp->content)
	{
		temp = temp->next;
		if (temp == a)
			return (0);
	}
	bigger = temp;
	n_bigger = *(int *)temp->content;
	temp = temp->next;
	while (temp != a)
	{
		if (n_bigger > *(int *)temp->content && *(int *)temp->content > n_push)
		{
			n_bigger = *(int *)temp->content;
			bigger = temp;
		}
		temp = temp->next;
	}
	while (a != bigger)
	{
		count++;
		a = a->next;
	}
	return (count);
}

void	ft_analisis_five(t_list **a, t_list **b)
{
	int	smallest;
	int	n_list;
	int	m_list;

	n_list = ft_count_list(*a);
	while (n_list > 3)
	{
		m_list = ft_mid_list(n_list);
		smallest = ft_find_small(*a);
		if (smallest <= m_list)
			ft_upper_list(a, b, smallest);
		else
			ft_down_list(a, b, smallest);

		n_list = ft_count_list(*a);
	}
	ft_end_list(a, b);
}

t_list	*ft_find_midchunk(t_list *c_analyze, t_chunk *new_chunk)
{
	t_list	*temp;

	temp = c_analyze;
	while (temp->next != c_analyze)
	{
		if (*(int *)temp->content <= (new_chunk->size_min + new_chunk->size_mid)
				&& !(*(int *)temp->content <= new_chunk->size_min))
			break ;
		temp = temp->next;
	}
	return (temp);
}

int	ft_is_bot(t_list *check, t_list *list)
{
	if (ft_last_list(list) == check)
		return (1);
	return (0);
}

void	ft_share_min(t_list **c_analyze, t_list **c_split, t_list **a, int bot)
{
	if (*c_analyze == *a)
	{
		if (bot == 0)
		{
			ft_push_b(c_analyze, c_split);
			ft_rotate_b(c_split);
		}
		else
		{
			ft_rev_rotate_a(c_analyze);
			ft_push_b(c_analyze, c_split);
			ft_rotate_b(c_split);
		}
	}
	else
	{
		if (bot  == 0)
			ft_rotate_b(c_analyze);
		else
			ft_rev_rotate_b(c_analyze);
	}
}

void	ft_share_mid(t_list **c_analyze, t_list **c_split, t_list **a, int bot)
{
	if (*c_analyze == *a)
	{
		if (bot == 0)
			ft_push_b(c_analyze, c_split);
		else
		{
			ft_rev_rotate_a(c_analyze);
			ft_push_b(c_analyze, c_split);
		}
	}
	else
	{
		if (bot == 0)
		{
			ft_push_a(c_split, c_analyze);
			ft_rotate_a(c_split);
		}
		else
		{
			ft_rev_rotate_b(c_analyze);
			ft_push_a(c_split, c_analyze);
			ft_rotate_a(c_split);
		}
	}
}

void	ft_share_max(t_list **c_analyze, t_list **c_split, t_list **a, int bot)
{
	if (*c_analyze == *a)
	{
		if (bot == 0)
			ft_rotate_a(c_analyze);
		else
			ft_rev_rotate_a(c_analyze);
	}
	else
	{
		if (bot == 0)
			ft_push_a(c_split, c_analyze);
		else
		{
			ft_rev_rotate_b(c_analyze);
			ft_push_a(c_split, c_analyze);
		}
	}
}

/*static int	ft_rr_min(t_list **c_analyze, t_list **c_split, int max, t_chunk *chunk)
{
	ft_push_b(c_analyze, c_split);
	if (max == 0)
		chunk->max = *c_analyze;
	ft_rotate_r(c_analyze, c_split);
	return (1);
}

static void	ft_rr_mid(t_list **c_analyze, t_list **c_split)
{
	ft_push_a(c_split, c_analyze);
	ft_rotate_r(c_split, c_analyze);
}*/

void	ft_share_split(t_chunk *new_chunk, t_list **c_analyze, t_list **c_split, t_list **a)
{
	int	mid;
	int	max;
	int	p;

	mid = 0;
	p = 0;
	max = 0;
	ft_numbers(*c_analyze, new_chunk->division);
	while (p < new_chunk->division)
	{
		if (*(int *)(*c_analyze)->content <= new_chunk->size_min)
		{
			/*if (((p + 1) < new_chunk->division) && c_analyze == a && *(int *)(*c_analyze)->next->content > (new_chunk->size_min + new_chunk->size_mid))
			{
				p++;
				max += ft_rr_min(c_analyze, c_split, max, new_chunk);
			}
			else*/
			ft_share_min(c_analyze, c_split, a, 0);
		}
		else if (*(int *)(*c_analyze)->content <= (new_chunk->size_min + new_chunk->size_mid))
		{
			if (mid == 0)
				new_chunk->mid = *c_analyze;
			/*if (((p + 1) < new_chunk->division) && c_analyze != a && *(int *)(*c_analyze)->next->content <= new_chunk->size_min)
			{
				p++;
				ft_rr_mid(c_analyze, c_split);
			}
			else*/
			ft_share_mid(c_analyze, c_split, a, 0);
			mid++;
		}
		else
		{
			if (max == 0)
				new_chunk->max = *c_analyze;
			ft_share_max(c_analyze, c_split, a, 0);
			max++;
		}
		p++;
	}
}

void	ft_share_split_bot(t_chunk *new_chunk, t_list **c_analyze, t_list **c_split, t_list **a)
{
	int	value;
	int	mid;
	int	min;
	int	max;
	int	p;

	min = 0;
	mid = 0;
	p = 0;
	max = 0;
	ft_rev_numbers(*c_analyze, new_chunk->division);
	while (p < new_chunk->division)
	{
		value = *(int *)(ft_last_list(*c_analyze))->content;

		if (value <= new_chunk->size_min)
		{
			if (min == 0)
				new_chunk->min = ft_last_list(*c_analyze);
			ft_share_min(c_analyze, c_split, a, 1);
			min++;
		}
		else if (value <= (new_chunk->size_min + new_chunk->size_mid))
		{
			if (mid == 0)
				new_chunk->mid = ft_last_list(*c_analyze);
			ft_share_mid(c_analyze, c_split, a, 1);
			mid++;
		}
		else
		{
			if (max == 0)
				new_chunk->max = ft_last_list(*c_analyze);
			ft_share_max(c_analyze, c_split, a, 1);
			max++;
		}
		p++;
	}
	if (c_analyze == a)
		new_chunk->min = ft_last_list(*c_split);
}

t_chunk	*ft_split_chunk_bot(int	n_chunk, t_list **c_analyze, t_list **c_split, t_list **a)
{
	t_chunk	*new_chunk;

	new_chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (!new_chunk)
		return (NULL);
	new_chunk->division = n_chunk;
	new_chunk->size_min = n_chunk / 3;
	if (n_chunk % 3 == 2)
	{
		new_chunk->size_max = (n_chunk / 3) + 1;
		new_chunk->size_mid = (n_chunk / 3) + 1;
	}
	else if (n_chunk % 3 == 1)
	{
		new_chunk->size_mid = (n_chunk / 3);
		new_chunk->size_max = (n_chunk / 3) + 1;
	}
	else
	{
		new_chunk->size_max = (n_chunk / 3);
		new_chunk->size_mid = (n_chunk / 3);
	}
	ft_share_split_bot(new_chunk, c_analyze, c_split, a);
	if (c_analyze != a)
	{
		new_chunk->mid = NULL;
		new_chunk->mid = ft_last_list(*c_split);
	}
	return (new_chunk);
}

t_list	*ft_last_list(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp->next != list)
		temp = temp->next;
	return (temp);
}

t_chunk	*ft_split_chunk(int	n_chunk, t_list **c_analyze, t_list **c_split, t_list **a)
{
	t_chunk	*new_chunk;

	new_chunk = (t_chunk *)malloc(sizeof(t_chunk));
	if (!new_chunk)
		return (NULL);
	new_chunk->division = n_chunk;
	new_chunk->size_min = n_chunk / 3;
	if (n_chunk % 3 == 2)
	{
		new_chunk->size_max = (n_chunk / 3) + 1;
		new_chunk->size_mid = (n_chunk / 3) + 1;
	}
	else if (n_chunk % 3 == 1)
	{
		new_chunk->size_mid = (n_chunk / 3);
		new_chunk->size_max = (n_chunk / 3) + 1;
	}
	else
	{
		new_chunk->size_max = (n_chunk / 3);
		new_chunk->size_mid = (n_chunk / 3);
	}
	ft_share_split(new_chunk, c_analyze, c_split, a);
	if (c_analyze != a)
	{
		new_chunk->mid = NULL;
		new_chunk->mid = ft_last_list(*c_split);
	}
	if (c_analyze != a)
		new_chunk->min = ft_last_list(*c_analyze);
	else
		new_chunk->min = ft_last_list(*c_split);
	if (c_analyze == a)
	{
		new_chunk->max = NULL;
		new_chunk->max = ft_last_list(*c_analyze);
	}
	return (new_chunk);
}

int	ft_lonely(t_list *check, int size, t_list *list)
{
	t_list	*temp;
	int p;

	temp = list;
	p = 0;
	while (p < size && temp->next != list)
	{
		temp = temp->next;
		p++;
	}
	if (check == temp)
		return (1);
	return (0);
}

t_chunk	*ft_decide_chunk(int flag, t_list **a, t_list **b, t_chunk *chunk)
{
	if	(flag == 1)
	{
		if (ft_is_bot(chunk->min, *b) == 0 || ft_lonely(chunk->min, chunk->size_min, *b))
			return (ft_split_chunk(chunk->size_min, b, a, a));
		else
			return (ft_split_chunk_bot(chunk->size_min, b, a, a));
	}
	else if (flag == 3)
		if (ft_is_bot(chunk->max, *a) == 0 || ft_lonely(chunk->max, chunk->size_max, *a))
			return (ft_split_chunk(chunk->size_max, a, b, a));
		else
			return (ft_split_chunk_bot(chunk->size_max, a, b, a));
	else if (ft_mid_a(chunk->mid, *a) == 0)
	{
			if (ft_is_bot(chunk->mid, *b) == 0)
				return (ft_split_chunk(chunk->size_mid, b, a, a));
			else
				return (ft_split_chunk_bot(chunk->size_mid, b, a, a));
	}
	else
	{
		if (ft_is_bot(chunk->mid, *a) == 0)
				return (ft_split_chunk(chunk->size_mid, a, b, a));
			else
				return (ft_split_chunk_bot(chunk->size_mid, a, b, a));
	}
}

int	ft_check_max(t_list *a, t_list *max)
{
	int	p;

	p = 0;
	while (p < 4)
	{
		if (a == max)
			return (1);
		a = a->next;
		p++;
	}
	return (0);
}

void	ft_rem_chunk(t_chunk **chunk)
{
	(*chunk)->size_min = 0;
	(*chunk)->size_max = 0;
	(*chunk)->size_mid = 0;
	(*chunk)->max = NULL;
	(*chunk)->mid = NULL;
	(*chunk)->min = NULL;
	free (*chunk);
}

void	ft_recursive_chunk_sort(t_chunk *chunk, t_list **a, t_list **b, int flag)
{
	t_chunk	*new;

	if (chunk->size_min < 5)
	{
		ft_small_sort(chunk, a, b, flag);
		return ;
	}
	new = ft_decide_chunk(flag, a, b, chunk);
	ft_recursive_chunk_sort(new, a, b, 3);
	ft_recursive_chunk_sort(new, a, b, 2);
	ft_recursive_chunk_sort(new, a, b, 1);
	ft_rem_chunk(&new);
}

void	ft_analisis_push(t_list **a, t_list **b)
{
	t_chunk	*cien;
	cien = ft_split_chunk(ft_count_list(*a), a, b, a);
	ft_recursive_chunk_sort(cien, a, b, 3);
	ft_recursive_chunk_sort(cien, a, b, 2);
	ft_recursive_chunk_sort(cien, a, b, 1);
	ft_rem_chunk(&cien);
	return ;
}
