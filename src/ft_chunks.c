/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:11:34 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/07 15:37:52 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_shrlist(t_list *a, int find)
{
	t_list	*temp;

	temp = a;
	if (*(int *)(temp->content) == find)
		return (1);
	temp = temp->next;
	while (temp!= a)
	{
		if (*(int *)(temp->content) == find)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	ft_find_nlist(t_list *list, int find)
{
	int	p;

	p = 1;
	while (p != find)
	{
		list = list->next;
		p++;
	}
	return (*(int *)(list->content));
}

int	ft_chunk_calculate(t_list *a, int psmall, int n_list)
{
	int	count;
	int	small;

	count = 0;
	small = ft_find_nlist(a, psmall);
	while (count < n_list)
	{
		if (ft_shrlist(a, small) == 1)
			count++;
		small++;
	}
	return (small);
}

int	ft_do_chunk(t_list **a, int chunk, int m_list)
{
	t_list *temp;
	int	p;
	int	psave;

	p = 1;
	psave = 0;
	temp = *a;
	while (psave == 0)
	{
		if (*(int *)(temp->content) < chunk)
			psave = p;
		else
		{
			temp = temp->next;
			p++;
		}
	}
	while (psave > 2 && temp != *a)
	{
		while (p < m_list)
		{
			temp = temp->next;
			p++;
		}
		if (*(int *)(temp->content) < chunk)
			psave = p;
		temp = temp->next;
		p++;
	}
	return (psave);
}

void	ft_chunk(t_list **a, t_list **b, int chunk, int n_list)
{
	int	p;
	int	m_list;

	m_list = ft_mid_list(n_list);
	p = ft_do_chunk(a, chunk, m_list);
	if (p <= m_list)
		ft_upper_list(a, b, p);
	else
		ft_down_list(a, b, p);
	/*
		p = ft_do_chunk(a, chunk, m_list);
		if (p == 0)
			break ;
		if (p <= m_list)
			ft_upper_list(a, b, p);
		else
			ft_down_list(a, b, p);
	}*/
}

void	ft_end_stackb(t_list **b, int p_smallest)
{
	int	end;
	int	lenght_b;

	end = ft_count_list(*b);
	lenght_b = ft_count_list(*b);
	while (p_smallest != end)
	{
		if (p_smallest <= ft_mid_list(lenght_b))
			ft_rotate_b(b);
		else
			ft_rev_rotate_b(b);
		p_smallest = ft_find_small(*b);
	}
}

void	ft_num_chunks(t_list **a, t_list **b, int n_list, int analisis)
{
	int	chunk;
	int	small;
	int	n_chunk;
	int	i;

	if (n_list % analisis != 0)
		n_chunk = n_list / analisis + (n_list % analisis);
	else
		n_chunk = n_list / analisis;
	small = ft_find_small(*a);
	chunk = ft_chunk_calculate(*a, small, n_chunk);
	while (ft_count_list(*b) < n_chunk)
		ft_chunk(a, b, chunk, n_list);
	//i = analisis - 1;
	n_chunk = n_list / analisis;
	ft_printf("chunk 1\n");
	while (analisis - 1)
	{
		i = 0;
		n_list = ft_count_list(*a);
		//n_chunk = n_list / analisis;
		small = ft_find_small(*a);
		chunk = ft_chunk_calculate(*a, small, n_chunk);
		while (i < n_chunk)
		{
			ft_chunk(a, b, chunk, n_list);
			i++;
		}
		analisis--;
		ft_printf("chunk \n");
		//i--;
	}
	//*a = NULL;
	ft_end_stackb(b, ft_find_small(*b));
	ft_push_all(a, b);
}
