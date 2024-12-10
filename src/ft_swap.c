/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:34:51 by lbellmas          #+#    #+#             */
/*   Updated: 2024/12/10 12:57:11 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_swap_a(t_list **a)
{
	t_list	*last;
	t_list	*second;
	if (*a == NULL || (*a)->next == NULL)
		return ;
	second = (*a)->next;
	last = *a;
	while (last->next != *a)
		last = last->next;
	last->next = (*a)->next;
	(*a)->next = last;
	second->next = *a;
	*a = second;
	ft_printf("swap a");
}

void	ft_swap_b(t_list **b)
{
	t_list	*last;
	t_list	*second;
	if (*b == NULL || (*b)->next == NULL)
		return ;
	second = (*b)->next;
	last = *b;
	while (last->next != *b)
		last = last->next;
	last->next = (*b)->next;
	(*b)->next = last;
	second->next = *b;
	*b = second;
	ft_printf("swap b");
}

void	ft_swap_s(t_list **a, t_list **b)
{
	t_list	*last;
	t_list	*second;
	if ((*b == NULL || (*b)->next == NULL) || (*a == NULL || (*a)->next == NULL))
		return ;
	second = (*b)->next;
	last = *b;
	while (last->next != *b)
		last = last->next;
	last->next = (*b)->next;
	(*b)->next = last;
	second->next = *b;
	*b = second;
	second = (*a)->next;
	last = *a;
	while (last->next != *a)
		last = last->next;
	last->next = (*a)->next;
	(*a)->next = last;
	second->next = *a;
	*a = second;
	ft_printf("swap s");
}
