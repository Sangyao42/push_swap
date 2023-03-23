/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_getter_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:29:06 by sawang            #+#    #+#             */
/*   Updated: 2023/03/23 16:24:08 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_atoi_input(unsigned int counter, char **input);

void	get_input(int argc, char **argv, t_stack *a, int **input_array)
{
	if (argc < 2)
		return ;
	// if (argc == 2)
	// 	get_input_split(argv, a, input_array);
	else
		get_input_argv(argc, argv, a, input_array);
}

unsigned int	get_input_split(char **argv, int **input_i_array)
{
	char			**input;
	unsigned int	i;

	input = ft_split(*argv, ' ');
	if (!input || !*input)
	{
		if (!*input)
			stringsfree(input);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (0);
	}
	i = 0;
	while (*(input + i))
		i++;
	if (input_is_valid(i, input) == EXIT_FAILURE)
	{
		stringsfree(input);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (0);
	}
	*input_i_array = ft_atoi_input(i, input);
	stringsfree(input);
	return (i);
}

void	get_input_argv(int argc, char **argv, t_stack *a, int **input_array)
{
	char			**input;
	unsigned int	elem_size;
	unsigned int	i;

	elem_size = 0;
	i = 1;
	while (i < argc)
	{
		input = NULL;
		elem_size = get_input_split(&argv[i], **input);
		if (elem_size == 0)
		{
			if (!*input_array)
				stringsfree(input_array);
			return (ft_putstr_fd("Error\n", STDERR_FILENO), EXIT_FAILURE);
		}
		input_array = ps_strs_join(a->max_size, input_array, input, elem_size);
		if (!input_array)
			return (ft_putstr_fd("Error\n", STDERR_FILENO), EXIT_FAILURE);
		a->max_size += elem_size;
		i++;
	}
}

int	**ps_strs_join(unsigned int max_size, int **input_array, \
	int *input, unsigned int elem_size)
{
	int	**new_input_array;
	int	i;

	i = 0;
	new_input_array = (int **)malloc(sizeof(int *) * (max_size + elem_size));
	if (!new_input_array)
	{
		free(input_array);
		return (NULL);
	}
	while (i < max_size)
	{
		*(new_input_array + i) = *(input_array + i);
		i++;
	}
	while (i < max_size + elem_size)
	{
		*(new_input_array + i) = *(input + i - max_size);
		i++;
	}
	free(input_array);
	return (new_input_array);
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
