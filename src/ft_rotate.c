/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:45:57 by lbellmas          #+#    #+#             */
/*   Updated: 2024/12/11 11:59:33 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rotate_a(t_list **a)
{
	*a = (*a)->next;
	ft_printf("rotate a\n");
}

void	ft_rotate_b(t_list **b)
{
	*b = (*b)->next;
	ft_printf("rotate b\n");
}

void	ft_rotate_r(t_list **a, t_list **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
	ft_printf("rotate r\n");
}
