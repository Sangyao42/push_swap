/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:44:34 by sawang            #+#    #+#             */
/*   Updated: 2023/03/23 17:53:33 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static unsigned int	get_input_split(char **argv, t_stack *a, int **input_array);
static void			get_input_argv(int argc, char **argv, \
	t_stack *a, int **input_array);

void	get_input(int argc, char **argv, t_stack *a, int **input_array)
{
	if (argc < 2)
		return ;
	if (argc == 2)
		get_input_split(argv, a, input_array);
	else
		get_input_argv(argc, argv, a, input_array);
}

static unsigned int	get_input_split(char **argv, t_stack *a, int **input_array)
{
	char	**input;

	input = ft_split(*(argv + 1), ' ');
	if (!input || !*input)
	{
		if (!*input)
			stringsfree(input);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (0);
	}
	while (*(input + a->max_size))
		a->max_size++;
	if (input_is_valid(a->max_size, input) == EXIT_FAILURE)
	{
		stringsfree(input);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (0);
	}
	*input_array = ft_atoi_input(a->max_size, input);
	stringsfree(input);
	return (a->max_size);
}

static void	get_input_argv(int argc, char **argv, t_stack *a, int **input_array)
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

