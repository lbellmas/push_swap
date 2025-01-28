/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:53:56 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/27 15:31:09 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_is_revsorted(t_list *list, int size)
{
	int		p;
	t_list	*temp;
	t_list	*prev;

	p = 0;
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

int	ft_is_sorted(t_list *list, int size)
{
	int		p;
	t_list	*temp;
	t_list	*prev;

	p = 0;
	if (ft_count_list(list) < 3)
		return (0);
	temp = list->next;
	prev = list;
	while (p < size && (temp != list))
	{
		if (*(int *)prev->content > *(int *)temp->content)
			return (0);
		temp = temp->next;
		prev = prev->next;
		p++;
	}
	return (1);
}

int	ft_mid_a(t_list *mid, t_list *a)
{
	t_list	*temp;

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

int	ft_is_revsorted_rev(t_list *list, int size)
{
	int		p;
	t_list	*temp;
	t_list	*prev;

	p = 0;
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

int	ft_is_sorted_rev(t_list *list, int size)
{
	int		p;
	t_list	*temp;
	t_list	*prev;

	p = 0;
	if (ft_count_list(list) < 3)
		return (0);
	temp = ft_last_list(list);
	prev = ft_prev(temp, list);
	while (p < size && (temp != list))
	{
		if (*(int *)prev->content > *(int *)temp->content)
			return (0);
		temp = ft_prev(temp, list);
		prev = ft_prev(prev, list);
		p++;
	}
	return (1);
}
