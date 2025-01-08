/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:04:44 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/08 11:26:02 by lbellmas         ###   ########.fr       */
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
void	ft_rotate_a(t_list **a);
void	ft_rotate_b(t_list **b);
void	ft_rotate_r(t_list **a, t_list **b);
void	ft_rev_rotate_a(t_list **a);
void	ft_rev_rotate_b(t_list **b);
void	ft_rev_rotate_r(t_list **a, t_list **b);
int	ft_count_list(t_list *a);
int	ft_mid_list(int n_list);
int	ft_find_small(t_list *a);
int	ft_find_big(t_list *a);
int	ft_find_smaller(t_list *a, int n_push);
int	ft_find_bigger(t_list *a, int n_push);
void	ft_analisis_push(t_list **a, t_list **b);
void	ft_upper_list(t_list **a, t_list **b, int p_small);
void ft_down_list(t_list **a, t_list **b, int p_small);
void	ft_push_all(t_list **a, t_list **b);
void	ft_end_list(t_list **a, t_list **b);
int	ft_error(char **args);
int	ft_error_num(char *arg);
void	ft_analisis_five(t_list **a, t_list **b);
int	ft_shrlist(t_list *a, int find);
int	ft_chunk_calculate(t_list *a, int small, int n_list);
int	ft_do_chunk(t_list **a, int chunk, int m_list);
void	ft_chunk(t_list **a, t_list **b, int chunk, int n_list);
void	ft_num_chunks(t_list **a, t_list **b, int n_list, int analisis);
void	ft_top_num(t_list **b, int p_smallest);
void	ft_min_num(t_list **b, int p_biggest);
void	ft_mid_num(t_list **b, int p_bigger, int n_push);
void	ft_check_bstack(int	n_push, t_list **b);


#endif
