/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:58 by yishan            #+#    #+#             */
/*   Updated: 2025/01/07 15:44:58 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//reverse rotation operation
//takes the last element of a stack (linked list) and moves it to the top
//stack: [A] → [B] → [C] → [D]
//stack: [D] → [A] → [B] → [C]

static void	ft_rr(t_list **stack)
{
	t_list	*tmp;
	t_list	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	end = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = tmp;
	(*stack)->next = NULL;
	*stack = end;
}

void	rra(t_list **stack1)
{
	ft_rr(stack1);
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack2)
{
	ft_rr(stack2);
	write(1, "rrb\n", 4);
}
