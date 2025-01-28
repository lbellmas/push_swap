/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_share.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:13:11 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/28 10:56:37 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

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
		if (bot == 0)
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
