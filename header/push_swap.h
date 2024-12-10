/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:04:44 by lbellmas          #+#    #+#             */
/*   Updated: 2024/12/10 15:58:57 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../printf/header/ft_printf.h"
# include "../printf/libft/libft.h"

char	*ft_hola(char *str);
t_list	*ft_setup(char **argv);
void	ft_status(t_list *a, t_list *b);
void	del(void *content);
void	ft_swap_a(t_list **a);
void	ft_swap_b(t_list **b);
void	ft_swap_s(t_list **a, t_list **b);
void	ft_push_a(t_list **a, t_list **b);
void	ft_push_b(t_list **a, t_list **b);
void	ft_first_push(t_list **add, t_list **push);
void	ft_last_push(t_list **add, t_list **rem);

#endif
