/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analisis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:57:41 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/08 12:05:28 by lbellmas         ###   ########.fr       */
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

void	ft_analisis_push(t_list **a, t_list **b)
{
	int	n_list;

	n_list = ft_count_list(*a);
	if (n_list <= 100)
		ft_num_chunks(a, b, n_list, 5);
	else if (n_list >= 500 )
		ft_num_chunks(a, b, n_list, 11);
	else
		ft_num_chunks(a, b, n_list, 7);
	return ;
}
