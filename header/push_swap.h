/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellmas <lbellmas@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:04:44 by lbellmas          #+#    #+#             */
/*   Updated: 2025/01/25 18:37:50 by lbellmas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../printf/header/ft_printf.h"
# include "../printf/libft/libft.h"

typedef	struct	s_chunk
{
	int	division;
	struct	s_list	*max;
	int	size_max;
	struct	s_list	*mid;
	int	size_mid;
	struct	s_list	*min;
	int	size_min;
}	t_chunk;

//char	*ft_hola(char *str);
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
int		ft_count_list(t_list *a);
int		ft_mid_list(int n_list);
int		ft_find_small(t_list *a);
int		ft_find_big(t_list *a);
int		ft_find_smaller(t_list *a, int n_push);
int		ft_find_bigger(t_list *a, int n_push);
void	ft_analisis_push(t_list **a, t_list **b);
void	ft_upper_list(t_list **a, t_list **b, int p_small);
void	 ft_down_list(t_list **a, t_list **b, int p_small);
void	ft_push_all(t_list **a, t_list **b);
void	ft_end_list(t_list **a, t_list **b);
int		ft_error(char **args);
int		ft_error_num(char *arg);
void	ft_analisis_five(t_list **a, t_list **b);
int		ft_shrlist(t_list *a, int find);
//int	ft_chunk_calculate(t_list *a, int small, int n_list);
//int	ft_do_chunk(t_list **a, int chunk, int m_list);
//void	ft_chunk(t_list **a, t_list **b, int chunk, int n_list);
//void	ft_num_chunks(t_list **a, t_list **b, int n_list, int analisis);
//void	ft_top_num(t_list **b, int p_smallest);
//void	ft_min_num(t_list **b, int p_biggest);
//void	ft_mid_num(t_list **b, int p_bigger, int n_push);
//void	ft_check_bstack(int	n_push, t_list **b);
//coreano
void	ft_share_min(t_list **c_analyze, t_list **c_split, t_list **a, int bot);
void	ft_share_mid(t_list **c_analyze, t_list **c_split, t_list **a, int bot);
void	ft_share_max(t_list **c_analyze, t_list **c_split, t_list **a, int bot);
void	ft_share_split(t_chunk *new_chunk, t_list **c_analyze, t_list **c_split, t_list **a);
void	ft_share_split_bot(t_chunk *new_chunk, t_list **c_analyze, t_list **c_split, t_list **a);
t_list	*ft_last_list(t_list *list);
t_chunk	*ft_split_chunk(int	n_chunk, t_list **c_analyze, t_list **c_split, t_list **a);
t_chunk	*ft_split_chunk_bot(int	n_chunk, t_list **c_analyze, t_list **c_split, t_list **a);
t_chunk	*ft_decide_chunk(int flag, t_list **a, t_list **b, t_chunk *chunk);
void	ft_recursive_chunk_sort(t_chunk *chunk, t_list **a, t_list **b, int flag);
void	ft_analisis_push(t_list **a, t_list **b);
int		ft_check_max(t_list *a, t_list *max);
t_list	*ft_find_midchunk(t_list *c_analyze, t_chunk *new_chunk);
void	ft_numbers(t_list *a, int n_max);
void	ft_rev_numbers(t_list *a, int n_max);
void	ft_small_sort(t_chunk *chunk, t_list **a, t_list **b, int flag);
void	ft_check_swap(t_list **a, t_list **b);
void	ft_sort_top_a(t_list **a, t_list **b, int size);
int		ft_prev_list(t_list *last, t_list *list);
void	ft_sort_bot_a(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_max(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_mid_bot(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_bot_a_two(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_min_2(t_list **b, t_list **a, t_chunk *chunk);
void	ft_sort_min(t_list **b, t_list **a, t_chunk *chunk);
void	ft_sort_mid_two(t_list **a, t_list **b);
void	ft_sort_mid_three(t_list **a, t_list **b);
void	ft_sort_mid(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_max(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_max_top(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_max_bot(t_list **a, t_list **b, t_chunk *chunk);
int		ft_is_bot(t_list *check, t_list *list);
void	ft_sort_bot_a_mid(t_list **a, t_list **b, t_chunk *chunk);
int		ft_mid_a(t_list *mid, t_list *a);
void	ft_min_is_top(t_list **a, t_list **b, t_chunk *chunk);
void	ft_sort_three_top(t_list **a);
int		ft_lonely(t_list *check, int size, t_list *list);
t_list	*ft_prev(t_list *last, t_list *list);
int		ft_is_revsorted_rev(t_list *list, int size);
int		ft_is_revsorted(t_list *list, int size);
int		ft_is_sorted(t_list *list, int size);
void	ft_sort_mid_min(t_list **a, t_list **b, t_chunk *chunk);
int		ft_is_sorted_rev(t_list *list, int size);

#endif
