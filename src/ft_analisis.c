/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analisis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:57:41 by lbellmas          #+#    #+#             */
/*   Updated: 2024/12/12 16:22:01 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_count_list(t_list *a)
{
	t_list	*temp;
	int	count;

	temp = a;
	count = 1;
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

void	ft_analisis_push(t_list **a, t_list **b)
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
	ft_end_list(a, b); //si hay en stack b pushea todo, sino solo ordena stack a
}
