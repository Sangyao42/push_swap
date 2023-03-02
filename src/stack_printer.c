/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:05:04 by sawang            #+#    #+#             */
/*   Updated: 2023/03/02 15:33:22 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_push_swap ps)
{
	unsigned int	i;
	unsigned int	idx;

	i = 0;
	idx = ps.a.front;
	printf("stack a: ");
	while (i < ps.a.size)
	{
		printf("%d\t", ps.a.elements[idx]);
		idx = next_idx(ps.a, idx);
		i++;
	}
	printf("\n");
	printf("%p, %d, %d, %d, %d\n", ps.a.elements, ps.a.front, ps.a.rear, ps.a.size, ps.a.max_size);
	i = 0;
	printf("array a: ");
	while (i < ps.a.max_size)
	{
		printf("%d\t", ps.a.elements[i]);
		i++;
	}
	printf("\n\n");
	i = 0;
	idx = ps.b.front;
	printf("stack b: ");
	while (i < ps.b.size)
	{
		printf("%d\t", ps.b.elements[idx]);
		idx = next_idx(ps.b, idx);
		i++;
	}
	printf("\n");
	printf("%p, %d, %d, %d, %d\n", ps.b.elements, ps.b.front, ps.b.rear, ps.b.size, ps.b.max_size);
	i = 0;
	printf("array b: ");
	while (i < ps.b.max_size)
	{
		printf("%d\t", ps.b.elements[i]);
		i++;
	}
	printf("\n\n");
}
