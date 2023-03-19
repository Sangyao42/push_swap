/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singel_tri_former_ascending.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:11:26 by sawang            #+#    #+#             */
/*   Updated: 2023/03/19 14:49:22 by sawang           ###   ########.fr       */
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
		merge_small_tri(ps, tri_info)
}

void	form_one_tri_size_6(from, to, ps.to_a_or_to_b, tri_shpae_A_or_D)
{
	int small_tri_info[3];
	small_tri_info[0] == 2;
	small_tri_info[1] == 2;
	small_tri_info[2] == 2;
	if (from->elements[from->front] > from->elements[next_idx(from->front)] && tri_shape == 'A'
		|| from->elements[from->front] < from->elements[next_idx(from->front)] && tri_shape == 'D')
		execute_instruction(S, to_a_or_to_b, from, to);
	execute_instruction(R, to_a_or_to_b, ps);
	execute_instruction(R, to_a_or_to_b, ps);
	execute_instruction(P, to_a_or_to_b, ps);
	execute_instruction(P, to_a_or_to_b, ps);
	if (to->elements[to->front] > to->elements[next_idx(to->front)] && tri_shape == 'A' \
		|| to->elements[to->front] < to->elements[next_idx(to->front)] && tri_shape == 'D')
		execute_instruction(S, !to_a_or_to_b, ps);
	if (from->elements[from->front] < from->elements[next_idx(from->front)] && tri_shape == 'A'\
		|| from->elements[from->front] < from->elements[next_idx(from->front)] && tri_shape == 'D')
		execute_instruction(S, to_a_or_to_b, from, to);
	execute_instruction(R, !to_a_or_to_b, ps);
	merge_small_tri(from, to, to_a_or_to_b, tri_info, small_tri_info[3]);
}

execute_instruction(instruction, to_a_or_to_b, from, to)
{
	instruction code = -1;
	if(to_a_or_to_b == 1)
	{
		if (instruction == S)
			execute_swap(from, to, )
		if (instruction == R)
		{
			rotate(from);
			instruction code = RA;
		}
		if (instruction == P)
		{
			push(from, to);
			instruction code PB;
		}
	}
	else if (instuction == S && to_a_or_to_b == -1)
	{
		swap(from);
		instruction code = SB;
	}


	print_instruction(instruction code);

}

execute_instruction(instruction, to_a_or_to_b, from, to)
{
	instruction code = -1;
	if(instruction == S)
	{
		
	}
		swap(from);
	if (a_to_b == 1)
		instruction code = SA
		if (instruction == R)
		{
			rotate(from);
			instruction code = RA;
		}
		if (instruction == P)
		{
			push(from, to);
			instruction code PB;
		}
	}
	else if (instuction == S && to_a_or_to_b == -1)
	{
		swap(from);
		instruction code = SB;
	}


	print_instruction(instruction code);

}

execute_swap(from, *instruction code)
{

}
