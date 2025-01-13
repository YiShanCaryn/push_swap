/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:52:58 by yishan            #+#    #+#             */
/*   Updated: 2025/01/09 10:27:14 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//reverse rotation operation
//takes the last element of a stack (linked list) and moves it to the top
//stack: [A] → [B] → [C] → [D]
//Traverse to the second-to-last element
//Link the last element (`end`) to the original top (`current`)
//Detach the last element from its previous position
//Make the last element (`end`) the new top of the stack
//stack: [D] → [A] → [B] → [C]

static void	ft_rr(t_list **stack)
{
	t_list	*current;
	t_list	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	current = *stack;
	end = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	end->next = current;
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
