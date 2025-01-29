/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:21:20 by yisho             #+#    #+#             */
/*   Updated: 2025/01/07 15:35:27 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//rotate operation on a stack
//moves the top element of the stack to the bottom
//shifting all other elements one position up
//stack: [A] → [B] → [C] → [D]
//stack: [B] → [C] → [D] → [A]

static void	ft_r(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}

void	ra(t_list **stack_a)
{
	ft_r(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	ft_r(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_r(stack_a);
	ft_r(stack_b);
	write(1, "rr\n", 3);
}
