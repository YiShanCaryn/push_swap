/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yisho <yisho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:59:57 by yisho             #+#    #+#             */
/*   Updated: 2025/01/29 16:59:59 by yisho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **node_ptr)
{
	t_list	*node;
	t_list	*buffer;

	node = *node_ptr;
	while (node)
	{
		buffer = node->next;
		free(node);
		node = buffer;
	}
	*node_ptr = NULL;
}
