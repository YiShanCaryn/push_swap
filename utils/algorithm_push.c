/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:10:44 by yishan            #+#    #+#             */
/*   Updated: 2025/01/11 13:26:23 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Save the second element of stack2
//Link the current top of stack2 to the top of stack1
//Move the top of stack2 to be the new top of stack1
//Update stack2 to point to its new top (previously second element)

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*push_b;

	if (!*stack_b)
		return ;
	push_b = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = push_b;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*push_a;

	if (!*stack_a)
		return ;
	push_a = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = push_a;
	ft_putstr_fd("pb\n", 1);
}
