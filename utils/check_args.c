/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yishan <yishan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:54:07 by yishan            #+#    #+#             */
/*   Updated: 2024/12/18 15:16:51 by yishan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_contains(int num, char **args, int current_index)
{
	int	next_index;

	if (!args || !args[current_index])
		return (0);

	next_index = current_index + 1;
	while (args[next_index])
	{
		if (ft_atoi(args[next_index]) == num)
			return (1);
		next_index++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	temp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv;
		i = 1;
	}
	while (argv[i])
	{
		temp = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i]))
			ft_error("Error");
		if (temp < -2147483648 || temp > 2147483647)
			ft_error("Error");
		if (ft_contains(temp, args, i))
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free(args);
}
