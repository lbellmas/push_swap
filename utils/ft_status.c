/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:18:44 by lbellmas          #+#    #+#             */
/*   Updated: 2024/12/10 16:14:44 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_status(t_list *a, t_list *b)
{
	int	check;
	t_list *tempa;
	t_list *tempb;

	tempa = a;
	tempb = b;
	ft_printf("stack a:  stack b:\n");
	while ((tempa && tempa->content) || (tempb && tempb->content))
	{
		if (tempa && tempa->content != NULL)
		{
			check = *(int *)(tempa->content);
			ft_printf("%-10i", check);
			tempa = tempa->next;
		}
		else
			ft_printf("          ");
		if (tempb && tempb->content != NULL)
		{
			check = *(int *)(tempb->content);
			ft_printf("%i", check);
			tempb = tempb->next;
		}
		if (tempa == a)
			tempa = NULL;
		if (tempb == b)
			tempb = NULL;
		ft_printf("\n");
	}
}
