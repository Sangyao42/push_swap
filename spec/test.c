/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:09:53 by sawang            #+#    #+#             */
/*   Updated: 2023/02/24 15:34:31 by sawang           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	unsigned int	i;
	t_stack			a;

	init_stack(&a);
	get_input(argc, argv, &a);
	if (!a.elements)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < a.max_size)
	{
		printf("element %d is %d\n", i, a.elements[i]);
		i++;
	}
	printf("%p, %d, %d, %d, %d\n", a.elements, a.front, a.rear, a.max_size, a.size);
	free(a.elements);
	a.elements = NULL;
	return (0);
}
