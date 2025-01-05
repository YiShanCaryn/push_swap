/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:16:16 by yishan            #+#    #+#             */
/*   Updated: 2025/01/03 15:22:01 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check(t_list *lst, long int n, char *nbr)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (nbr[i])
	{
		if (!(((nbr[i] == '-' || nbr[i] == '+') && ft_isdigit(nbr[i + 1])
					&& (i == 0 || !ft_isdigit(nbr[i - 1])))
				|| ft_isdigit(nbr[i])))
			return (0);
		i++;
	}
	while (tmp)
	{
		if ((int)(intptr_t)(tmp->content) == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list	*ft_init(char **argvs, int argc)
{
	int			i;
	long int	nbr;
	t_list		*res;
	t_list		*tmp;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	res = NULL;
	while (argvs[i])
	{
		nbr = ft_atoi(argvs[i]);
		if (nbr > INT_MAX || nbr < INT_MIN || ft_check(res, nbr, argvs[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&res, tmp);
		tmp->index = -1;
		i++;
	}
	return (res);
}

int	main(int argc, char **argv)
{
	t_swap	*tab;
	char	**argvs;

	if (argc == 1)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	if (argc == 2)
		argvs = ft_split(argv[1], ' ');
	else
		argvs = argv;
	tab->stack_a = ft_init(argvs, argc);
	if (tab->stack_a == NULL)
		return (-1);
	tab->stack_b = NULL;
	tab->asize = ft_lstsize(tab->stack_a);
	tab->bsize = ft_lstsize(tab->stack_b);
	add_index(tab->stack_a);
	check_sort(tab);
}
