/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_indexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:37:22 by sawang            #+#    #+#             */
/*   Updated: 2023/03/22 22:32:48 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_index_b(t_stack st, unsigned int element_idx)
{
	unsigned int	index_b;
	unsigned int	next;

	index_b = 0;
	next = st.front;
	while (next != element_idx)
	{
		index_b++;
		next = next_idx(st, next);
	}
	return (index_b);
}

unsigned int	get_index_a_is_sorted(t_push_swap *ps, unsigned int element_idx)
{
	unsigned int	index_a;
	unsigned int	next;

	index_a = 0;
	if (ps->b.elements[element_idx] > ps->a.elements[ps->a.front] && \
		ps->b.elements[element_idx] < ps->a.elements[ps->a.rear])
	{
		next = ps->a.front;
		while (ps->b.elements[element_idx] > ps->a.elements[next])
		{
			index_a++;
			next = next_idx(ps->a, next);
		}
	}
	return (index_a);
}

unsigned int	get_index_ra(t_push_swap *ps, unsigned int element_idx)
{
	unsigned int	index_a;
	unsigned int	next;
	unsigned int	index_temp;

	index_a = 0;
	next = ps->a.front;
	index_temp = next;
	while (ps->b.elements[element_idx] > ps->a.elements[next] && \
		ps->a.elements[next] >= ps->a.elements[index_temp])
	{
		index_temp = next;
		index_a++;
		next = next_idx(ps->a, next);
	}
	return (index_a);
}

unsigned int	get_index_rra(t_push_swap *ps, unsigned int element_idx)
{
	unsigned int	index_a;
	unsigned int	prev;
	unsigned int	index_a_rev;
	unsigned int	index_temp;

	index_a = 0;
	index_a_rev = 0;
	prev = ps->a.rear;
	index_temp = prev;
	while (ps->b.elements[element_idx] < ps->a.elements[prev] && \
		ps->a.elements[prev] <= ps->a.elements[index_temp])
	{
		index_temp = prev;
		index_a_rev++;
		prev = prev_idx(ps->a, prev);
	}
	index_a = ps->a.size - index_a_rev;
	return (index_a);
}
