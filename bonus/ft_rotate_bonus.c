/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:45:57 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/28 14:54:21 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_rotate_a2(t_list **a)
{
	*a = (*a)->next;
}

void	ft_rotate_b2(t_list **b)
{
	*b = (*b)->next;
}

void	ft_rotate_r2(t_list **a, t_list **b)
{
	*a = (*a)->next;
	*b = (*b)->next;
}
