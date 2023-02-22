/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:44:34 by sawang            #+#    #+#             */
/*   Updated: 2023/02/22 22:26:53 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_input(int argc, char **argv)
{
	int		*elements;

	if (argc < 2)
		return (NULL);
	else if (argc == 2)
		elements = get_input_split(argv);
	else
		elements = get_input_argv(argc, argv);
	// if (!elements)
	// 	return (NULL);
	return (elements);
}

int	*get_input_split(char **argv)
{
	char	**input;
	int		counter;
	int		*elements;

	counter = 0;
	input = ft_split(*(argv + 1), ' ');
	if (!input)
		return (NULL);
	if (!*input)
		return (stringsfree(input), NULL);
	while (input + counter)
		counter++;
	if (input_is_not_valid(counter, input))
		return (stringsfree(input), ft_putstr_fd(2, "Error\n"), NULL);
	elements = ft_atoi_input(counter, input);
	// if (!elements)
	// 	return (NULL);
	return (stringsfree(input), elements);
}

int	*get_input_argv(int argc, char **argv)
{
	char	**input;
	int		counter;
	int		*elements;

	counter = 0;
	input = argv + 1;
	counter = argc - 1;
	if (input_is_not_valid(counter, input))
		return (ft_putstr_fd(2, "Error\n"), NULL);
	elements = ft_atoi_input(counter, input);
	// if (!elements)
	// 	return (NULL);
	return (elements);
}

int	*ft_atoi_input(int counter, char **input)
{
	int	i;
	int	*elements;

	elements = (int *)malloc(sizeof(int) * counter);
	if (!elements)
		return (NULL);
	i = 0;
	while (i < counter)
	{
		elements[i] = ft_atoi(input[i]);
		i++;
	}
	return (elements);
}
