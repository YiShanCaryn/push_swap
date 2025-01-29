/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:46:41 by yishan            #+#    #+#             */
/*   Updated: 2025/01/29 16:18:30 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>

typedef struct s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		asize;
	int		bsize;
}	t_swap;

typedef struct s_push
{
	int	next_index;
	int	max_index;
	int	mid;
	int	flag;
}	t_push;

//helper check functions
void	add_index(t_list *lst);
void	check_sort(t_swap	*tab);
int		check_sorting(t_list **stack1);
int		is_reverse_sorted(t_swap	*tab);
t_list	*find_min_index(t_list	**stack);
t_list	*find_max_index(t_list	**stack);
int		is_stack_sorted(t_list	**stack1, int total_count);
void	quick_sort(t_list **stack1, t_list **stack2, int total_count);

//algorithm utils
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

#endif
