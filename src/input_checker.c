/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:36:02 by sawang            #+#    #+#             */
/*   Updated: 2023/03/24 14:56:33 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_is_valid(int arg_num, char **input)
{
	int		i;
	char	**input_cpy;

	input_cpy = input;
	i = 0;
	while (i < arg_num)
	{
		if (i < (arg_num - 1))
		{
			if (is_duplicate(*(input + i), &(*(input + i + 1)), arg_num, i) \
				== EXIT_SUCCESS)
				return (EXIT_FAILURE);
		}
		if (is_valid_int(*(input + i)) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	is_duplicate(char *str, char **input, int arg_num, int arg_idx)
{
	int	i;

	i = 0;
	while (i < arg_num - 1 - arg_idx)
	{
		if (ps_strcmp(str, *(input + i)) == 0)
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int	is_valid_int(const char *str)
{
	int			sign;
	long long	value;

	sign = 1;
	if (!*str)
		return (EXIT_FAILURE);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str = str + 1;
	}
	if (*str > '9' || *str < '0')
		return (EXIT_FAILURE);
	value = 0;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		value = 10 * value;
		value = value + (*str - '0');
		if ((value * sign) > INT_MAX || (value * sign) < INT_MIN)
			return (EXIT_FAILURE);
		str++;
	}
	return (*str != 0);
}
