/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:09:53 by sawang            #+#    #+#             */
/*   Updated: 2023/02/24 20:43:30 by sawang           ###   ########.fr       */
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

void	init_ps(t_push_swap *ps)
{
	init_stack(&(ps->a));
	init_stack(&(ps->b));
	ps->max_size = 0;
}

int	main(int argc, char **argv)
{
	unsigned int	i;
	// t_stack			a;
	t_push_swap ps;

	init_ps(&ps);
	get_input(argc, argv, &(ps.a));
	ps.max_size = ps.a.max_size;
	ps.b.max_size = ps.a.max_size;
	if (!ps.a.elements)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < ps.a.max_size)
	{
		printf("initial element %d in stack a is %d\n", i, ps.a.elements[i]);
		i++;
	}
	printf("%p, %d, %d, %d, %d\n", ps.a.elements, ps.a.front, ps.a.rear, ps.a.max_size, ps.a.size);
	// test_operations(&ps);
	free(ps.a.elements);
	ps.a.elements = NULL;
}

// void	test_opeations(t_push_swap *ps)
// {
// 	command(*ps, )
// }
