/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:30:31 by yishan            #+#    #+#             */
/*   Updated: 2025/01/13 12:58:50 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3numbers(t_swap	*tab)
{
	t_list	*last;

	if (check_sorting(&tab->stack_a))
		return ;
	last = ft_lstlast(tab->stack_a);
	if (is_reverse_sorted(tab) == 1)
	{
		sa(&tab->stack_a);
		rra(&tab->stack_a);
	}
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content < last->content)
		sa(&tab->stack_a);
	else if (tab->stack_a->content > last->content
		&& tab->stack_a->next->content < last->content)
		ra(&tab->stack_a);
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content > last->content)
	{
		sa(&tab->stack_a);
		ra(&tab->stack_a);
	}
	else if (tab->stack_a->content > last->content
		&& tab->stack_a->next->content > last->content)
		rra(&tab->stack_a);
}

void	sort_5numbers(t_swap	*tab)
{
	int	length;

	length = ft_lstsize(tab->stack_a);
	while (length--)
	{
		if (tab->stack_a->index == 0 || tab->stack_a->index == 1)
			pb(&tab->stack_a, &tab->stack_b);
		else
			ra(&tab->stack_a);
	}
	sort_3numbers(tab);
	pa(&tab->stack_a, &tab->stack_b);
	pa(&tab->stack_a, &tab->stack_b);
	if (tab->stack_a->content > tab->stack_a->next->content)
		sa(&tab->stack_a);
}

void	check_sort(t_swap	*tab)
{
	int	length;

	length = ft_lstsize(tab->stack_a);
	if (check_sorting(&tab->stack_a))
		return ;
	if (length == 2)
	{
		if (tab->stack_a->content > tab->stack_a->next->content)
			sa(&tab->stack_a);
	}
	else if (length == 3)
		sort_3numbers(tab);
	else if (length == 5)
		sort_5numbers(tab);
	else
		quick_sort(&tab->stack_a, &tab->stack_b, ft_lstsize(tab->stack_a));
}
