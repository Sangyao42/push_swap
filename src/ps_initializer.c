/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:33:02 by sawang            #+#    #+#             */
/*   Updated: 2023/03/22 22:20:13 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack	*a)
{
	a->elements = NULL;
	a->front = 0;
	a->rear = 0;
	a->max_size = 0;
	a->size = 0;
}

void	init_ps(t_push_swap *ps, int argc, char **argv)
{
	int	*input_array;

	input_array = NULL;
	init_stack(&(ps->a));
	init_stack(&(ps->b));
	get_input(argc, argv, &(ps->a), &input_array);
	if (!input_array)
		exit(EXIT_FAILURE);
	index_input(&ps->a, input_array);
	if (!ps->a.elements)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ps->max_size = ps->a.max_size;
	ps->b.max_size = ps->a.max_size;
	ps->b.elements = ft_calloc(ps->b.max_size, sizeof(unsigned int));
	if (!ps->b.elements)
	{
		free(ps->a.elements);
		exit(EXIT_FAILURE);
	}
}
