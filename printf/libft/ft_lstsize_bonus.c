/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:31:38 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/27 13:52:34 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		count;

	if (!lst)
		return (0);
	count = 1;
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

/*int	main()
{
	t_list	*test3 = ft_lstnew("hola");
	t_list  *test2 = ft_lstnew("hola");
	t_list  *test1 = ft_lstnew("hola");

	test3->next = test2;
	test2->next = test1;
	printf("%i", ft_lstsize(test1));
	return (0);
}*/
