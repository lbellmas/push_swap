/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:47 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/30 16:17:21 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	del(void *content)
{
	free(content);
	content = NULL;
}

void	ft_end_stack(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!*lst)
		return ;
	if ((*lst)->content == NULL)
	{
		free(lst);
		return ;
	}
	temp = *lst;
	while (temp->next != *lst)
		temp = temp->next;
	temp->next = NULL;
	ft_lstclear(lst, del);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	b = NULL;
	if (argc < 2 || ft_error(argv) == -1)
	{
		write (2, "ERROR\n", 6);
		return (0);
	}
	a = ft_setup(argv);
	ft_numbers(a, ft_count_list(a));
	if (ft_count_list(a) > 5)
		ft_analisis_push(&a, &b);
	else
		ft_analisis_five(&a, &b);
	ft_end_stack(&a, del);
	return (0);
}
