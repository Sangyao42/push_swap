/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:39:08 by sawang            #+#    #+#             */
/*   Updated: 2023/03/19 21:52:02 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	index_input(int t_push_swap *ps)
// {
// 	int				*input_cpy;
// 	int				cpy_idx;
// 	unsigned int	element_idx;
// 	int 			size_idx;
// 	int				index;

// 	size_idx = 0;
// 	element_idx = ps->a.front;
// 	while (size_idx < ps->a.size)
// 	{
// 		// cpy_idx = 0;
// 		// index = 0;
// 		// while (cpy_idx < ps->a.size)
// 		// {
// 		// 	if (input_cpy[cpy_idx] < ps->a.elements[element_idx])
// 		// 		index++;
// 		// 	cpy_idx++;
// 		// }
// 		// ps->a.elements[element_idx] = index;
// 		ps->a.elements[element_idx] = get_index(input_array, ps);
// 		element_idx = next_idx(ps->a, element_idx);
// 		size_idx++;
// 	}
// }

void	index_input(t_stack *a, int *input_array)
{
	unsigned int	*indexed_array;
	unsigned int	element_idx;
	unsigned int	size_idx;

	indexed_array = malloc(a->size * sizeof(unsigned int));
	if (!indexed_array)
	{
		free(input_array);
		return ;
	}
	size_idx = 0;
	element_idx = a->front;
	while (size_idx < a->size)
	{
		indexed_array[element_idx] = \
			get_index(input_array[size_idx], input_array, a->size);
		element_idx = next_idx(*a, element_idx);
		size_idx++;
	}
	free(input_array);
	a->elements = indexed_array;
}

unsigned int	get_index(int to_compare, int *input_array, \
	unsigned int input_array_size)
{
	unsigned int	element_idx;
	unsigned int	index;

	element_idx = 0;
	index = 0;
	while (element_idx < input_array_size)
	{
		if (input_array[element_idx] < to_compare)
			index++;
		element_idx++;
	}
	return (index);
}
