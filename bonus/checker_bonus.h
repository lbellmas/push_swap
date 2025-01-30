/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:49:24 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/30 16:23:14 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "../printf/header/ft_printf.h"
# include "../printf/libft/libft.h"
# include "get_next_line_bonus.h"

int	ft_moves(t_list **a, t_list **b);
int		ft_check(t_list **a, t_list **b);
void	ft_push_a2(t_list **a, t_list **b);
void	ft_push_b2(t_list **a, t_list **b);
void	ft_rev_rotate_a2(t_list **a);
void	ft_rev_rotate_b2(t_list **b);
void	ft_rev_rotate_r2(t_list **a, t_list **b);
void	ft_rotate_a2(t_list **a);
void	ft_rotate_r2(t_list **a, t_list **b);
void	ft_rotate_b2(t_list **b);
void	ft_swap_a2(t_list **a);
void	ft_swap_b2(t_list **b);
void	ft_swap_s2(t_list **a, t_list **b);

#endif
