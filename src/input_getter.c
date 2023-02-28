/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:44:34 by sawang            #+#    #+#             */
/*   Updated: 2023/02/28 15:47:38 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*ft_atoi_input(unsigned int counter, char **input);

void	get_input(int argc, char **argv, t_stack *a)
{
	if (argc < 2)
		return ;
	else if (argc == 2)
		get_input_split(argv, a);
	else
		get_input_argv(argc, argv, a);
	// if (!elements)
	// 	return (NULL);
	// return (a);
}

void	get_input_split(char **argv, t_stack *a)
{
	char	**input;

	input = ft_split(*(argv + 1), ' ');
	if (!input || !*input)
	{
		if (!*input)
			stringsfree(input);
		ft_putstr_fd("1Error\n", 2);
		return ;
	}
	while (*(input + a->max_size))
		a->max_size++;
	if (input_is_not_valid(a->max_size, input))
	{
		stringsfree(input);
		ft_putstr_fd("1Error\n", 2);
		return ;
	}
	a->elements = ft_atoi_input(a->max_size, input);
	a->size = a->max_size;
	a->rear = a->max_size - 1;
	stringsfree(input);
}

void	get_input_argv(int argc, char **argv, t_stack *a)
{
	char	**input;

	input = argv + 1;
	a->max_size = argc - 1;
	if (input_is_not_valid(a->max_size, input))
	{
		ft_putstr_fd("2Error\n", 2);
		return ;
	}
	a->elements = ft_atoi_input(a->max_size, input);
	a->size = a->max_size;
	a->rear = a->max_size - 1;
	// if (!elements)
	// 	return (NULL);
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
