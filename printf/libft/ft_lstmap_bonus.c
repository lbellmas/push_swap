/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 11:49:36 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/24 18:52:08 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*temp;
	t_list	*backup;

	if (!del || !f || !lst)
		return (NULL);
	backup = lst;
	start = ft_lstnew(f(backup->content));
	if (!start)
		return (NULL);
	backup = backup->next;
	temp = start;
	while (backup != NULL)
	{
		temp->next = ft_lstnew(f(backup->content));
		if (!temp)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		backup = backup->next;
		temp = temp->next;
	}
	return (start);
}

/*void	*f(void *content)
{
	char	*str;
	str = (char *)content;
	str = "hola";
	return (str);
}

void	del(void *content)
{
	content = NULL;
	free (content);
}

int	main()
{
	t_list	*comprobar;
	t_list	*test;
	t_list	*test2;
	t_list	*test3;

	test = ft_lstnew("adeu");
	test2 = ft_lstnew("adeu");
	test3 = ft_lstnew("adeu");
	test->next = test2;
	test2->next = test3;
	test3->next = NULL;
	printf("%s", (char *)test->content);
	printf("%s", (char *)test2->content);
	printf("%s", (char *)test3->content);
	comprobar = ft_lstmap(test, f, del);
	while (comprobar != NULL)
	{
		printf("%s", (char *)comprobar->content);
		comprobar = comprobar->next;
	}
	return (0);
}*/
