/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:44:34 by sawang            #+#    #+#             */
/*   Updated: 2023/02/21 23:00:13 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_isdigit(char c)
{
	if (c > '9' || c < '0')
		return (1);
	else
		return (0);
}

static int	ps_strcmp(char *s1, char *s2)
{
	int	i;
	int	ret_val;

	i = 0;
	ret_val = 0;
	while (s1[i] || s2[i])
	{
		ret_val = s1[i] - s2[i];
		if (ret_val != 0)
			return (ret_val);
		else
			ret_val = 0;
		i++;
	}
	return (ret_val);
}

static int	ps_atoi(const char *str)
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
	while (*str != '\0' && ('0' <= *str && *str <= '9'))
	{
		value = 10 * value;
		value = value + (*str - '0');
		if ((value * sign) > INT_MAX || (value * sign) < INT_MIN)
			return (1);
		str++;
	}
	return ((int) value * sign);
}

int	input_is_valid(int arg_num, char **input)
{
	int		i;
	char	**input_cpy;

	input_cpy = input;
	i = 0;
	while (i < arg_num)
	{
		if (is_int(*input + i))
			return (1);
		if (is_duplicate((*input + 1 + i), input_cpy, arg_num))
			return (1);
		if (is_in_range(*input + i))
			return (1);
		i++;
	}
	return (0);
}

// int	all_is_int(int argc, char **input)
// {
// 	int	i;

// 	i = 0;
// 	while (i < (argc - 1))
// 	{
// 		if (is_int((*input + 1) + i))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (!*str)
		return (1);
	while (*str + i)
	{
		if (ps_isdigit(*str + i))
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

int	is_in_range(char *str)
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

int	**check_input(int argc, char **argv)
{
	char	**input;
	int		counter;
	int		i;

	counter = 0;
	i = 0;
	if (argc < 2)
		ft_putstr_fd(2, "Error\n");
	else if (argc == 2)
	{
		input = ft_split(*(argv + 1), ' ');
		if (!input)
			return (NULL);
		if (!*input)
			return (stringsfree(input), NULL);
		while (input + counter)
			counter++;
		if (input_is_valid(counter, input))
			return (stringsfree(input), NULL);
		// input = cut the last \0;
	}
	else
	{
		input = argv + 1;
		counter = argc - 1;
		if (input_is_valid(counter, input))
			return (NULL);
	}
	return (input);
}


	// input_array = (int *)malloc(sizeof(int *) * counter);
	// while (i < counter)
	// {
	// 	input_array[i] = ft_atoi(input[i]);
	// 	i++;
	// }
	// return (input_array);
