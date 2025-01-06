/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:30:31 by yishan            #+#    #+#             */
/*   Updated: 2025/01/06 18:50:30 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3nbr(t_swap *tab)
{
	t_list	*last;

	if (check_sorting(&tab->stack_a))
		return ;
	last = ft_lstlast(tab->stack_a);
	if (isrevsorted(tab) == 1)
	{
		sa(&tab->stack_a);
		rra(&tab->stack_a);
	}
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content < last->content)
		sa(&tab->stack_a);
}

void	check_sort(t_swap	*tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	if (check_sorting(&tab->stack_a))
		return ;
	if (len == 2)
	{
		if (tab->stack_a->content > tab->stack_a->next->content)
			sa(&tab->stack_a);
	}
	else if (len == 3)
		sort_3nbr(tab);
	else if (len == 5)
		sort_5nbr(tab);
}
