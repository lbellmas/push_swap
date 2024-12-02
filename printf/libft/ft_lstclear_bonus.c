/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:59:21 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/27 13:07:07 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*rem;
	t_list	*mov;

	if (!del || !lst)
		return ;
	rem = *lst;
	while (rem != NULL)
	{
		mov = rem->next;
		ft_lstdelone(rem, del);
		rem = mov;
	}
	*lst = NULL;
}

/*void	del(void *content)
{
	content = NULL;
	free (content);
}

int	main()
{
	t_list	**test;
	t_list	*test2;
	t_list	*test3;

	test = (t_list **)malloc(sizeof(t_list *));
	test2 = ft_lstnew("caracola");
	test3 = ft_lstnew("adeu");
	*test = test2;
	test2->next = test3;
	test3->next = NULL;
	ft_lstclear(test, del);
	printf("%s", (char *)test2->content);
	return (0);
}*/
