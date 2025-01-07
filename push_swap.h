/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:46:41 by yishan            #+#    #+#             */
/*   Updated: 2025/01/07 10:23:57 by yisho            ###   ########.fr       */
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

//helper check functions
void	add_index(t_list *lst);
void	check_sort(t_swap	*tab);
int		check_sorting(t_list **stack1);
int		isrevsorted(t_swap	*tab);

//algorithm utils
void	sa(t_list **stack1);
void	sb(t_list **stack2);
void	ss(t_list **stack1, t_list **stack2);
void	rra(t_list **stack1);
void	rrb(t_list **stack2);
void	ra(t_list **stack1);
void	rb(t_list **stack2);
void	rr(t_list **stack1, t_list **stack2);

#endif
