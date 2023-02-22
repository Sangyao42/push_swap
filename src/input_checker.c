/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:36:02 by sawang            #+#    #+#             */
/*   Updated: 2023/02/22 17:36:33 by sawang           ###   ########.fr       */
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
		if (is_non_int(*input + i))
			return (1);
		if (is_duplicate((*input + 1 + i), input_cpy, arg_num))
			return (1);
		if (is_not_in_range(*input + i))
			return (1);
		i++;
	}
	return (0);
}

int	is_non_int(char *str)
{
	int	i;

	i = 0;
	if (!*str)
		return (1);
	while (*str + i)
	{
		if (ps_is_non_digit(*str + i))
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicate(char *str, char **input, int arg_num)
{
	int	i;

	i = 0;
	while (i < arg_num)
	{
		if (ps_strcmp(str, *input + i))
			return (1);
		i++;
	}
	return (0);
}

int	is_not_in_range(char *str)
{
	int	i;

	i = 0;
	while (*str + i)
	{
		if (ps_atoi(*str + i))
			return (1);
		i++;
	}
	return (0);
}
