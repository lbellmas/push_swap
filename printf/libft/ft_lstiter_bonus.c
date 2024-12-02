/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:11:15 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/27 15:45:26 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	if (!lst || !f)
		return ;
	while (temp != NULL)
	{
		f(temp->content);
		temp = temp->next;
	}
}

/*void	f(void *content)
{
	t_list	*str;
	str = (t_list *)content;
	str->content = "hola";
	return ;
}

int	main()
{
	t_list	*test;
	t_list	*test2;
	t_list	*test3;

	test = ft_lstnew("adeu");
	test2 = ft_lstnew("adeu");
	test3 = ft_lstnew("adeu");
	test->next = test2;
	test2->next = test3;
	test3->next = NULL;
	ft_lstiter(test, f);
	printf("%s", (char *)test->content);
	printf("%s", (char *)test2->content);
	printf("%s", (char *)test3->content);
	return (0);
}*/
