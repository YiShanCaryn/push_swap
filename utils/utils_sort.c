/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:04:53 by yishan            #+#    #+#             */
/*   Updated: 2025/01/13 14:29:20 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sorting(t_list **stack)
{
	t_list	*current;

	if (!stack || !*stack)
		return (1);
	current = *stack;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_reverse_sorted(t_swap	*tab)
{
	t_list	*current;

	if (!tab || !tab->stack_a)
		return (1);
	current = tab->stack_a;
	while (current->next)
	{
		if (current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

t_list	*find_min_index(t_list	**stack)
{
	t_list	*current;
	t_list	*min;

	current = *stack;
	min = *stack;
	while (current)
	{
		if (current->content < min->content)
			min = current;
		current = current->next;
	}
	return (min);
}

t_list	*find_max_index(t_list	**stack)
{
	t_list	*current;
	t_list	*max;

	current = *stack;
	max = *stack;
	while (current)
	{
		if (current->content > max->content)
			max = current;
		current = current->next;
	}
	return (max);
}

int	is_stack_sorted(t_list	**stack1, int total_count)
{
	int	length;

	length = ft_lstsize(*stack1);
	if (length != total_count)
		return (0);
	if (check_sorting(stack1) == 0)
		return (0);
	return (1);
}
