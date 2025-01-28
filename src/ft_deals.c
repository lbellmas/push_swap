/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:35:38 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/28 10:55:00 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_share_split_bot(t_chunk *new_chunk, t_list **c_analyze,
		t_list **c_split, t_list **a)
{
	int	value;

	ft_rev_numbers(*c_analyze, new_chunk->division);
	while (new_chunk->p++ < new_chunk->division)
	{
		value = *(int *)(ft_last_list(*c_analyze))->content;
		if (value <= new_chunk->size_min)
		{
			if (new_chunk->min == NULL)
				new_chunk->min = ft_last_list(*c_analyze);
			ft_share_min(c_analyze, c_split, a, 1);
		}
		else if (value <= (new_chunk->size_min + new_chunk->size_mid))
		{
			if (new_chunk->mid == NULL)
				new_chunk->mid = ft_last_list(*c_analyze);
			ft_share_mid(c_analyze, c_split, a, 1);
		}
		else
		{
			if (new_chunk->max == NULL)
				new_chunk->max = ft_last_list(*c_analyze);
			ft_share_max(c_analyze, c_split, a, 1);
		}
	}
}
