/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:51:53 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/20 16:24:48 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"
#include <limits.h>

t_list	*ft_prev_tlist(t_list *last, t_list *list)
{
	while (list->next != last)
		list = list->next;
	return (list);
}

void ft_numbers(t_list *a, int size)
{
    t_list *head;
    t_list *node;
    int current_order;
    int min_processed;
	int		i;	

	i = 0;
    current_order = 1;
    min_processed = -2147483648;
    while (current_order <= size)
    {
		i = 0;
        head = a;
        node = NULL;
        while (head->next != head && i < size)
        {
            if ((*(int *)head->content > min_processed) && (!node || *(int *)head->content < *(int *)node->content))
                node = head;
            head = head->next;
			i++;
        }
        if (node)
        {
            *(int *)node->content = current_order;
            min_processed = *(int *)node->content;
            current_order++;
        }
		else
			break ;
    }
	//ft_status(a, NULL);
}

void ft_rev_numbers(t_list *a, int size)
{
    t_list *head;
    t_list *node;
    int current_order;
    int min_processed;
	int		i;	

	i = 0;
    current_order = 1;
    min_processed = -2147483648;
    while (current_order <= size)
    {
		i = 0;
        head = ft_last_list(a);
        node = NULL;
        while (head->next != head && i < size)
        {
            if ((*(int *)head->content > min_processed) && (!node || *(int *)head->content < *(int *)node->content))
                node = head;
            head = ft_prev_tlist(head, a);
			i++;
        }
        if (node)
        {
            *(int *)node->content = current_order;
            min_processed = *(int *)node->content;
            current_order++;
        }
    }
}
