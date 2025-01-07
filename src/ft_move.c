/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:18:02 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/07 15:31:55 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
int	ft_find_closer(t_list *b, int find)
{
	int	p;
	t_list	*temp;

	p = 1;
	temp = b;
	find--;
	while (temp)
	{
		if (*(int *)(temp)->content == find)
			return (p);
		temp = temp->next;
		p++;
		if (temp == b)
			find--;
	}
	return (0);
}
void	ft_small_down(int psmall, t_list **b, int n_list)
{
	int	m_list;

	m_list = ft_mid_list(n_list);
	if (psmall >= m_list)
		ft_rev_rotate_b(b);
	else
		ft_rotate_b(b);
}

void	ft_upp_down_b(int p, t_list **b)
{
	int	m_list;

	m_list = ft_mid_list(ft_count_list(*b));
	if (p <= m_list)
		ft_rotate_b(b);
	else
		ft_rev_rotate_b(b);
}

/*void	ft_check_bstack(int	n_push, t_list **b)
{
	int	n_list;
	int	p;
	int	p_small;
	t_list	*temp;

	p = 1;
	temp = *b;
	n_list = ft_count_list(*b);
	if (n_list < 2)
		return ;
	if (n_push < *(int *)(temp)->content)
	{
		while (n_push < *(int *)(temp)->content)
		{
			temp = temp->next;
			p++;
			if (temp == *b)
			{
				p = ft_find_small(*b);
				while (ft_find_small(*b) != 1)
					ft_upp_down_b(p, b);
				return ;
			}
		}
		while (n_push < *(int *)(*b)->content)
			ft_upp_down_b(p, b);
		return ;
	}
	p_small = ft_find_closer(*b, n_push);
	while (p_small != 1)
	{
		ft_upp_down_b(p_small, b);
		p_small = ft_find_closer(*b, n_push);
	}
}*/  

void	ft_check_bstack(int	n_push, t_list **b)
{
	int	smaller;
	int	bigger;

	smaller = ft_find_smaller(*b, n_push);
	bigger = ft_find_bigger(*b, n_push);
	if (smaller != 0 && bigger != 0)
		ft_mid_num(b, bigger, n_push);
	else if (bigger != 0)
		ft_min_num(b, ft_find_big(*b));
	else
		ft_top_num(b, ft_find_small(*b));
}

void	ft_mid_num(t_list **b, int p_bigger, int n_push)
{
	int	lenght_b;

	lenght_b = ft_count_list(*b);
	while (p_bigger != 1)
	{
		if (p_bigger < ft_mid_list(lenght_b))
			ft_rotate_b(b);
		else
			ft_rev_rotate_b(b);
		p_bigger = ft_find_bigger(*b, n_push);
	}
}

void	ft_min_num(t_list **b, int p_biggest)
{
	int	end;
	int	lenght_b;

	lenght_b = ft_count_list(*b);
	end = ft_count_list(*b);
	while (p_biggest != end)
	{
		if (p_biggest <= ft_mid_list(lenght_b))
			ft_rotate_b(b);
		else
			ft_rev_rotate_b(b);
		p_biggest = ft_find_big(*b);
	}
}

void	ft_top_num(t_list **b, int p_smallest)
{
	int	lenght_b;

	lenght_b = ft_count_list(*b);
	while (p_smallest != 1)
	{
		if (p_smallest < ft_mid_list(lenght_b))
			ft_rotate_b(b);
		else
			ft_rev_rotate_b(b);
		p_smallest = ft_find_small(*b);
	}
}

void	ft_upper_list(t_list **a, t_list **b, int p_small)
{
	while (p_small > 1)
	{
		ft_rotate_a(a);
		p_small--;
	}
	if (*b && ft_count_list(*b) > 2)
		ft_check_bstack(*(int *)(*a)->content, b);
	ft_push_b(a, b);
}

void ft_down_list(t_list **a, t_list **b, int p_small)
{
	int	max;

	max = ft_count_list(*a);
	while(p_small < max)
	{
		ft_rev_rotate_a(a);
		p_small++;
	}
	ft_rev_rotate_a(a);
	if (*b)
		ft_check_bstack(*(int *)(*a)->content, b);
	ft_push_b(a, b);
}

void	ft_push_all(t_list **a, t_list **b)
{
	while (*b)
	{
		ft_push_a(a, b);
	}
}

void	ft_end_list(t_list **a, t_list **b)
{
	int	check;
	int	smallest;

	check = 0;
	while (check != 2)
	{
		check = 0;
		smallest = ft_find_small(*a);
		if (smallest == 3)
			ft_rev_rotate_a(a);
		else if (smallest == 2)
			ft_swap_a(a);
		else
			check++;
		if ((*a)->next->next != *a &&
				*(int *)((*a)->next->content) > *(int *)((*a)->next->next->content))
			ft_rev_rotate_a(a);
		else
			check++;
	}
	ft_push_all(a, b);
}
