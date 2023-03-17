/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singel_tri_former_ascending.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:11:26 by sawang            #+#    #+#             */
/*   Updated: 2023/03/17 20:49:31 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	form_single_tri_size_6(t_stack *from, t_stack *to)
{
	// if (tri_shape_i == A)
	// {
		if (from->elements[from->front] > from->elements[next_idx(from->front)])
			// rotate(from, FRONT);
			swap(from);
			// add_command(from);??????
		rotate(from, FRONT);
		rotate(from, FRONT);
		push(from, to);
		push(from, to);
		// if (from->elements[from->front] < from->elements[next_idx(from->front)] \
		// && to->elements[to->front] > to->elements[next_idx(to->front)])
		if (from->elements[from->front] < from->elements[next_idx(from->front)])
			swap(from);
		if (to->elements[to->front] > to->elements[next_idx(to->front)])
			swap(to);
		rotate(to, FRONT);
		rotate(to, FRONT);
	// }
}
