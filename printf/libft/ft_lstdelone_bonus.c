/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:33:04 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/24 09:58:41 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free (lst);
}

/*void	del(void *content)
{
	content = NULL;
	free (content);
}

int	main()
{
	t_list	*test;

	test = ft_lstnew("hola");
	ft_lstdelone(test, del);
	printf("%s", (char *)test->content);
	return (0);
}*/
