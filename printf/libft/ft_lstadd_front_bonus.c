/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:23:44 by lbellmas          #+#    #+#             */
/*   Updated: 2024/09/23 13:15:02 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int	main()
{
	t_list	*test = ft_lstnew("hola");
	t_list	*test2 = ft_lstnew("adeu");
	printf("%s", (char *)test->content);
	printf("%s", (char *)test2->content);
	ft_lstadd_front(&test, test2);
	printf("%s", (char *)test->content);
	printf("%s", (char *)test2->content);
}*/
