/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:33:27 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/26 17:02:30 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

/*int	main()
{
	t_list	*test;
	t_list	test2;
	t_list	test3;
	t_list	*anadir;

	anadir = ft_lstnew("hola");
	test = &test2;
	test2.next = &test3;
	test3.next = NULL;
	test3.content = "adeu";
	ft_lstadd_back(&test, anadir);
	printf("%s", (char *)ft_lstlast(test)->content);
	return (0);
}*/
