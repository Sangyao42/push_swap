/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_former.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:54:25 by sawang            #+#    #+#             */
/*   Updated: 2023/03/17 20:48:22 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to_b_first_is_needed(int tri_amount)
{
	if (tri_amount == 3, 27, 243)
		// push all elements in a to b first
		return (1);
	if (tri_amount == 9, 81)
		return (0);
}

form_single_tri(t_stack *from, t_stack *to, tri_info)
{
	if (ps.a.size == 0)
		form_tri_in_a;
	if (ps.b.size == 0)
		form_tri_in_b;
	if (tri_info.tri_shape == 'A')
		if (tri_info.tri_size == 6)
			form_single_tri_size_6_A(from, to, A);
		if (tri_info.tri_size == 5)
			form_single_tri_size_5(from, to, A);
		if (tri_info.tri_size == 4)
		if (tri_info.tri_size == 3)
		if (tri_info.tri_size == 2)
	if (tri_info.tri_shape == 'D')
		if (tri_info.tri_size == 6)
		if (tri_info.tri_size == 5)
		if (tri_info.tri_size == 4)
		if (tri_info.tri_size == 3)
		if (tri_info.tri_size == 2)
}

form_triangle(ps, tri_info)
{
	push_to_b_first_is_needed();
	if (needed == true)
		push all a to b;
	if (ps.a.size == 0)
	{
		while (i < tri_amount)
		{
			form_single_tri(ps.b, ps.a , tri_info.tri_shape[i], tri_info.tri_size[i]);
			i++;
		}
	}
	if (ps.b.size == 0)
	{
		while (i < tri_amount)
		{
			form_single_tri(ps.a, ps.b , tri_info.tri_shape[i], tri_info.tri_size[i]);
			i++;
		}
	}
}
