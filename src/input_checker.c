/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:36:02 by sawang            #+#    #+#             */
/*   Updated: 2023/02/24 19:28:48 by sawang           ###   ########.fr       */
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
		// printf("address of inputis %p\n", input);
		// printf("address of (input + %d) is %p\n", i, (*input + i));
		// printf("value of (input + %d) is %s\n", i, *(input + i));
		// if (is_non_int(*(input + i)))
		// 	return (1);
		if (i < (arg_num - 1))
		{
			if (is_duplicate(*(input + i), &(*(input + i + 1)), arg_num, i))
				return (1);
		}
		// if (is_not_in_range(*(input + i)))
		// 	return (1);
		if (is_not_valid_int(*(input + i)))
			return (ft_putstr_fd("is not valid int Error\n", 2), 1);
		i++;
	}
	return (0);
}

// int	is_non_int(char *str)
// {
// 	int	i;

// 	i = 0;
// 	// printf("value of (input + %d) is %s\n", i, str + i);
// 	if (!*str)
// 		return (1);
// 	if (*str == '-' || *str == '+')
// 		str = str + 1;
// 	while (*(str + i))
// 	{
// 		if (ps_is_non_digit(*(str + i)))
// 			return (ft_putstr_fd("non integer Error\n", 2), 1);
// 		i++;
// 	}
// 	return (0);
// }

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

// int	is_not_in_range(char *str)
// {
// 	if (ps_atoi(str))
// 		return (ft_putstr_fd("not in range Error\n", 2), 1);
// 	return (0);
// }

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
