/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:44:34 by sawang            #+#    #+#             */
/*   Updated: 2023/03/22 22:44:42 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_atoi_input(unsigned int counter, char **input);

void	get_input(int argc, char **argv, t_stack *a, int **input_array)
{
	if (argc < 2)
		return ;
	if (argc == 2)
		get_input_split(argv, a, input_array);
	else
		get_input_argv(argc, argv, a, input_array);
}

void	get_input_split(char **argv, t_stack *a, int **input_array)
{
	char	**input;

	input = ft_split(*(argv + 1), ' ');
	if (!input || !*input)
	{
		if (!*input)
			stringsfree(input);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return ;
	}
	while (*(input + a->max_size))
		a->max_size++;
	if (input_is_valid(a->max_size, input) == EXIT_FAILURE)
	{
		stringsfree(input);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return ;
	}
	*input_array = ft_atoi_input(a->max_size, input);
	a->size = a->max_size;
	a->rear = a->max_size - 1;
	stringsfree(input);
}

void	get_input_argv(int argc, char **argv, t_stack *a, int **input_array)
{
	char	**input;

	input = argv + 1;
	a->max_size = argc - 1;
	if (input_is_valid(a->max_size, input) == EXIT_FAILURE)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return ;
	}
	*input_array = ft_atoi_input(a->max_size, input);
	a->size = a->max_size;
	a->rear = a->max_size - 1;
}

static int	*ft_atoi_input(unsigned int counter, char **input)
{
	unsigned int	i;
	int				*elements;

	elements = (int *)ft_calloc(counter, sizeof(int));
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
