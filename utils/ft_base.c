/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:41:52 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/30 16:32:17 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

t_list	*ft_setup(char **argv)
{
	int		p;
	int		num;
	t_list	*dest;
	t_list	*temp;

	p = 2;
	num = ft_atoi(argv[1]);
	temp = ft_lstnew((void *)malloc(sizeof(int)));
	*(int *)temp->content = num;
	dest = temp;
	temp = temp->next;
	while (argv[p])
	{
		num = ft_atoi(argv[p]);
		temp = ft_lstnew((void *)malloc(sizeof(int)));
		*(int *)(temp->content) = num;
		ft_lstadd_back(&dest, temp);
		p++;
	}
	temp->next = dest;
	temp = NULL;
	ft_lstdelone(temp, del);
	return (dest);
}

t_list	*ft_prev_tlist(t_list *last, t_list *list)
{
	while (list->next != last)
		list = list->next;
	return (list);
}
