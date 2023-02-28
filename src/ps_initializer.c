/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_initializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:33:02 by sawang            #+#    #+#             */
/*   Updated: 2023/02/28 15:59:51 by sawang           ###   ########.fr       */
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
	init_stack(&(ps->a));
	init_stack(&(ps->b));
	get_input(argc, argv, &(ps->a));
	if (!ps->a.elements)
		exit(EXIT_FAILURE);
	ps->max_size = ps->a.max_size;
	ps->b.max_size = ps->a.max_size;
	ps->b.elements = (int *)ft_calloc(ps->b.max_size, sizeof(int));
	if (!ps->b.elements)
	{
		free(ps->a.elements);
		exit(EXIT_FAILURE);
	}
}
