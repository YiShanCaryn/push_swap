/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:57:51 by yishan            #+#    #+#             */
/*   Updated: 2025/01/07 15:50:27 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//swap operation
//stack: [A] → [B] → [C] → [D]
//stack: [B] → [A] → [C] → [D]

static void	ft_s(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_list **stack_a)
{
	ft_s(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	ft_s(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_s(stack_a);
	ft_s(stack_b);
	write(1, "ss\n", 3);
}
