/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:44:34 by sawang            #+#    #+#             */
/*   Updated: 2023/02/22 17:38:55 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_input(int argc, char **argv)
{
	int		*input_arr;

	if (argc < 2)
	{
		ft_putstr_fd(2, "Error\n");
		return (NULL);
	}
	else if (argc == 2)
		input_arr = get_input_split(argv);
	else
		input_arr = get_input_argv(argc, argv);
	if (!input_arr)
		return (NULL);
	return (input_arr);
}

int	*get_input_split(char **argv)
{
	char	**input;
	int		counter;
	int		*input_arr;

	counter = 0;
	input = ft_split(*(argv + 1), ' ');
	if (!input)
		return (NULL);
	if (!*input)
		return (stringsfree(input), NULL);
	while (input + counter)
		counter++;
	if (input_is_valid(counter, input))
		return (stringsfree(input), NULL);
	input_arr = ft_atoi_input(counter, input);
	if (!input_arr)
		return (NULL);
	return (stringsfree(input), input_arr);
}

int	*get_input_argv(int argc, char **argv)
{
	char	**input;
	int		counter;
	int		*input_arr;

	counter = 0;
	input = argv + 1;
	counter = argc - 1;
	if (input_is_valid(counter, input))
		return (NULL);
	input_arr = ft_atoi_input(counter, input);
	if (!input_arr)
		return (NULL);
	return (input_arr);
}

int	*ft_atoi_input(int counter, char **input)
{
	int	i;
	int	*input_arr;

	input_arr = (int *)malloc(sizeof(int) * counter);
	if (!input_arr)
		return (NULL);
	i = 0;
	while (i < counter)
	{
		input_arr[i] = ft_atoi(input[i]);
		i++;
	}
	return (input_arr);
}
