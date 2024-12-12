/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:50:11 by lbellmas          #+#    #+#             */
/*   Updated: 2024/12/12 16:01:50 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rev_rotate_a(t_list **a)
{
	t_list	*last;

	last = *a;
	while (last->next != *a)
		last = last->next;
	*a = last;
	ft_printf("reverse rotate a\n");
}

void	ft_rev_rotate_b(t_list **b)
{
	t_list	*last;

	last = *b;
	while (last->next != *b)
		last = last->next;
	*b = last;
	ft_printf("reverse rotate b\n");
}

void	ft_rev_rotate_r(t_list **a, t_list **b)
{
	t_list	*last;

	last = *a;
	while (last->next != *a)
		last = last->next;
	*a = last;
	last = *b;
	while (last->next != *b)
		last = last->next;
	*b = last;
	ft_printf("reverse rotate r\n");
}
