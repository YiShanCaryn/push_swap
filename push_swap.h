/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:46:41 by yishan            #+#    #+#             */
/*   Updated: 2024/12/16 15:04:42 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

//util functions
void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
void	ft_free(char **str);

//algorithm utils

//instruction functions

#endif
