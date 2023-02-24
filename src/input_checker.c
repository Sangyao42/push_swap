/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:36:02 by sawang            #+#    #+#             */
/*   Updated: 2023/02/24 19:31:14 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_is_not_valid(int arg_num, char **input)
{
	int		i;
	char	**input_cpy;

	input_cpy = input;
	i = 0;
	while (i < arg_num)
	{
		if (i < (arg_num - 1))
		{
			if (is_duplicate(*(input + i), &(*(input + i + 1)), arg_num, i))
				return (1);
		}
		if (is_not_valid_int(*(input + i)))
			return (ft_putstr_fd("is not valid int Error\n", 2), 1);
		i++;
	}
	return (0);
}

int	is_duplicate(char *str, char **input, int arg_num, int arg_idx)
{
	int	i;

	i = 0;
	while (i < arg_num - 1 - arg_idx)
	{
		if (ps_strcmp(str, *(input + i)) == 0)
			return (ft_putstr_fd("duplicate Error\n", 2), 1);
		i++;
	}
	return (0);
}

int	is_not_valid_int(const char *str)
{
	int			sign;
	long long	value;

	sign = 1;
	while (is_non_space(*str) == 1)
		str = str + 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str = str + 1;
	}
	value = 0;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		value = 10 * value;
		value = value + (*str - '0');
		if ((value * sign) > INT_MAX || (value * sign) < INT_MIN)
			return (ft_putstr_fd("not in range Error\n", 2), 1);
		str++;
	}
	return (*str != 0);
}
