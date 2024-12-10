/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:42:21 by lbellmas          #+#    #+#             */
/*   Updated: 2024/12/10 16:21:39 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_last_push(t_list **add, t_list **rem)
{
	t_list	*last;

	(*rem)->next = *add;
	last = *add;
	while (last->next != *add)
		last = last->next;
	last->next = *rem;
	*add = *rem;
	*rem = NULL;
}

void	ft_first_push(t_list **add, t_list **push)
{
	t_list	*last;

	*add = *push;
	*push = (*push)->next;
	last = *push;
	while (last->next != *add)
		last = last->next;
	last->next = *push;
	(*add)->next = *add;
}

void	ft_push_a(t_list **a, t_list **b)
{
	t_list	*second;
	t_list	*last;

	second = *a;
	last = *b;
	if (!*b)
		return ;
	if (!*a)
	{
		ft_first_push(a, b);
		ft_printf("push a\n");
		return ;
	}
	if ((*b)->next == *b)
	{
		ft_last_push(a, b);
		ft_printf("push a\n");
		return ;
	}
	while (last->next != *b)
		last = last->next;
	last->next = (*b)->next;
	*a = *b;
	*b = last->next;
	(*a)->next = second;
	while (second->next != (*a)->next)
		second = second->next;
	second->next = *a;
	ft_printf("push a\n");
}

void	ft_push_b(t_list **a, t_list **b)
{
	t_list	*second;
	t_list	*last;

	second = *b;
	last = *a;
	if (!*a)
		return ;
	if (!*b)
	{
		ft_first_push(b, a);
		ft_printf("push b\n");
		return ;
	}
	if ((*a)->next == *a)
	{
		ft_last_push(b, a);
		ft_printf("push b\n");
		return ;
	}
	while (last->next != *a)
		last = last->next;
	last->next = (*a)->next;
	*b = *a;
	*a = last->next;
	(*b)->next = second;
	while (second->next != (*b)->next)
		second = second->next;
	second->next = *b;
	ft_printf("push b\n");
}
