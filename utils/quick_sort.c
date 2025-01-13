/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:35:06 by yishan            #+#    #+#             */
/*   Updated: 2025/01/13 14:30:16 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Find n places the next smallest element (push->next_index) in correct position
/*if the top of stack2 matches next, push it to stack1 (pa()).
If the top of stack1 matches next, mark it as sorted by setting its flag to -1 
and rotate (ra()).
If the last element of stack2 matches next, reverse rotate stack2 (rrb()).
If the second element in stack1 matches next, swap the top two elements (sa()).
If stack1's second element and stack2's second element match next and next + 1, 
swap both (ss())*/
void	place_next_in_order(t_list **stack1, t_list **stack2, t_push *push)
{
	if (ft_lstsize(*stack2) > 0 && ((*stack2)->index == push->next_index))
		pa(stack1, stack2);
	else if ((*stack1)->index == push->next_index)
	{
		(*stack1)->flag = -1;
		ra(stack1);
		push->next_index++;
	}
	else if ((ft_lstsize(*stack2)) > 2
		&& ft_lstlast(*stack2)->index == push->next_index)
		rrb(stack2);
	else if ((*stack1)->next->index == push->next_index)
		sa(stack1);
	else if ((ft_lstsize(*stack1)) > 1
		&& ((*stack1)->next->index == push->next_index)
		&& ((*stack2)->next->index == push->next_index + 1))
		ss(stack1, stack2);
	else
		return ;
	place_next_in_order(stack1, stack2, push);
}

//splits elements from stack1 into stack2 for processing
void	split_stack1(t_list **stack1, t_list **stack2, t_push *push)
{
	int	current_flag;

	current_flag = (*stack1)->flag;
	if ((*stack1)->flag != 0)
	{
		while ((*stack1)->flag == current_flag)
		{
			if ((*stack1)->index != push->next_index)
				pb(stack1, stack2);
			place_next_in_order(stack1, stack2, push);
		}
	}
	else if ((*stack1)->flag == 0)
	{
		while ((*stack1)->flag != -1)
		{
			if ((*stack1)->index != push->next_index)
				pb(stack1, stack2);
			place_next_in_order(stack1, stack2, push);
		}
	}
	if (ft_lstsize(*stack2) > 0)
		push->max_index = (find_max_index(stack2))->index;
	push->mid = (push->max_index - push->next_index) / 2 + push->next_index;
}

//Processes elements from stack2 and places them back into stack1 
//if they belong to the current range
void	move_larger_to_stack1(t_list **stack1, t_list **stack2, t_push *push)
{
	int	i;
	int	count_b;

	i = -1;
	count_b = ft_lstsize(*stack2);
	while (ft_lstsize(*stack2) && ++i < count_b)
	{
		if ((*stack2)->index == push->next_index)
			place_next_in_order(stack1, stack2, push);
		else if ((*stack2)->index >= push->mid)
		{
			(*stack2)->flag = push->flag;
			pa(stack1, stack2);
		}
		else if ((*stack2)->index < push->mid)
			rb(stack2);
	}
	push->max_index = push->mid;
	push->mid = (push->max_index - push->next_index) / 2 + push->next_index;
	push->flag++;
}

//split stack1 into initial subsets
//split_stack_by_midpoint
void	begin_sorting(t_list **stack1, t_list **stack2, t_push *push, int count)
{
	int	i;

	i = -1;
	while (i++ < count)
	{
		if ((*stack1)->index <= push->mid)
			pb(stack1, stack2);
		else
		{
			if (ft_lstsize(*stack2) > 1 && (*stack2)->index < (push->mid / 2))
				rr(stack1, stack2);
			else
				ra(stack1);
		}
	}
	push->max_index = push->mid;
	push->mid = (push->max_index - push->next_index) / 2 + push->next_index;
	push->flag++;
}

//coordinates entire sorting process
void	quick_sort(t_list **stack1, t_list **stack2, int total_count)
{
	t_push	push;

	push.next_index = find_min_index(stack1)->index;
	push.max_index = find_max_index(stack1)->index;
	push.mid = push.max_index / 2 + push.next_index;
	push.flag = 0;
	begin_sorting(stack1, stack2, &push, total_count);
	while (!(is_stack_sorted(stack1, total_count)))
	{
		if (ft_lstsize(*stack2) == 0)
			split_stack1(stack1, stack2, &push);
		else
			move_larger_to_stack1(stack1, stack2, &push);
	}
}
