/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_getter_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:29:06 by sawang            #+#    #+#             */
/*   Updated: 2023/03/24 00:00:50 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int			*ps_ints_join(unsigned int max_size, int *input_array, \
	int *input, unsigned int elem_size);
static unsigned int	get_input_split(char **argv, int **input_i_array);
static void			get_input_argv(int argc, char **argv, t_stack *a, \
	int **input_array);
static int			int_is_duplicate(int *input_array, unsigned int size);

void	get_input(int argc, char **argv, t_stack *a, int **input_array)
{
	if (argc < 2)
		return ;
	else
		get_input_argv(argc, argv, a, input_array);
	if (!*input_array)
		return ;
	else
		if (int_is_duplicate(*input_array, a->max_size) == EXIT_FAILURE)
			*input_array = NULL;
}

static unsigned int	get_input_split(char **argv, int **input_i_array)
{
	char			**input;
	unsigned int	i;

	input = ft_split(*argv, ' ');
	if (!input || !*input)
	{
		if (!*input)
			stringsfree(input);
		return (ft_putstr_fd("Error\n", STDERR_FILENO), 0);
	}
	i = 0;
	while (*(input + i))
		i++;
	if (input_is_valid(i, input) == EXIT_FAILURE)
	{
		stringsfree(input);
		return (ft_putstr_fd("Error\n", STDERR_FILENO), 0);
	}
	*input_i_array = ft_atoi_input(i, input);
	stringsfree(input);
	return (i);
}

static void	get_input_argv(int argc, char **argv, t_stack *a, int **input_array)
{
	int				*input_i_array;
	unsigned int	elem_size;
	int				i;

	elem_size = 0;
	i = 1;
	while (i < argc)
	{
		elem_size = get_input_split(&argv[i], &input_i_array);
		if (elem_size == 0)
		{
			if (*input_array)
			{
				free(*input_array);
			}
			*input_array = NULL;
			return ;
		}
		*input_array = ps_ints_join(a->max_size, *input_array, \
			input_i_array, elem_size);
		if (!*input_array)
			return ;
		a->max_size += elem_size;
		i++;
	}
}

static int	*ps_ints_join(unsigned int max_size, int *input_array, \
	int *input, unsigned int elem_size)
{
	int				*new_input_array;
	unsigned int	i;

	if (max_size == 0)
		return (input);
	new_input_array = (int *)malloc(sizeof(int) * (max_size + elem_size));
	if (!new_input_array)
	{
		free(input_array);
		return (NULL);
	}
	i = 0;
	while (i < max_size)
	{
		new_input_array[i] = input_array[i];
		i++;
	}
	while (i < max_size + elem_size)
	{
		new_input_array[i] = input[i - max_size];
		i++;
	}
	free(input_array);
	free(input);
	return (new_input_array);
}

static int	int_is_duplicate(int *input_array, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (input_array[i] == input_array[j])
			{
				free(input_array);
				ft_putstr_fd("Error\n", STDERR_FILENO);
				return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
