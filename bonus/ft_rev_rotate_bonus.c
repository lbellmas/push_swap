/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:50:11 by lbellmas          #+#    #+#             */
/*   Updated: 2025/02/03 10:39:13 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rev_rotate_a2(t_list **a)
{
	t_list	*last;

	if (!*a || (*a)->next == (*a))
		return ;
	last = *a;
	while (last->next != *a)
		last = last->next;
	*a = last;
}

void	ft_rev_rotate_b2(t_list **b)
{
	t_list	*last;

	if (!*b || (*b)->next == (*b))
		return ;
	last = *b;
	while (last->next != *b)
		last = last->next;
	*b = last;
}

void	ft_rev_rotate_r2(t_list **a, t_list **b)
{
	t_list	*last;

	if (!*a || (*a)->next == (*a))
		return (ft_rev_rotate_b2(b));
	if (!*b || (*b)->next == (*b))
		return (ft_rev_rotate_a2(a));
	last = *a;
	while (last->next != *a)
		last = last->next;
	*a = last;
	last = *b;
	while (last->next != *b)
		last = last->next;
	*b = last;
}
