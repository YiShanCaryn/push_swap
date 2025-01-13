/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:34:50 by yishan            #+#    #+#             */
/*   Updated: 2025/01/09 15:19:07 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_replace(t_list *lst, int min, int i)
{
	t_list	*current;

	current = lst;
	while (current)
	{
		if (current->index == -1 && current->content == min)
			break ;
		current = current->next;
	}
	current->index = i;
}

int	min_nbr(t_list *lst)
{
	t_list		*current;
	long int	min;

	min = LONG_MAX;
	current = lst;
	while (current)
	{
		if (current->index == -1 && current->content < min)
			min = current->content;
		current = current->next;
	}
	return (min);
}

void	add_index(t_list *lst)
{
	int	length;
	int	i;
	int	min;

	i = 0;
	length = ft_lstsize(lst);
	while (i < length)
	{
		min = min_nbr(lst);
		index_replace(lst, min, i);
		i++;
	}
}
