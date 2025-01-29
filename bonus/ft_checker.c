/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:55:19 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/29 13:50:09 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../header/push_swap.h"

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
	int		check;

	b = NULL;
	if (argc < 2 || ft_error(argv) == -1)
	{
		ft_printf("ERROR");
		return (0);
	}
	a = ft_setup(argv);
	ft_moves(&a, &b);
	check = ft_check(&a, &b);
	ft_end_stack(&a, del);
	ft_end_stack(&b, del);
	if (check == -1)
		ft_printf("KO");
	else
		ft_printf("OK");
	return (0);
}
