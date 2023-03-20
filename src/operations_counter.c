/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_counter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:37:22 by sawang            #+#    #+#             */
/*   Updated: 2023/03/20 22:00:47 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_cmd_cost(t_cmd_cost *cost)
{
	cost->rb = 0;
	cost->rrb = 0;
	cost->ra = 0;
	cost->rra = 0;
	cost->rr = 0;
	cost->rrr = 0;
	cost->cmd_cost = 0;
}

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

// unsigned int	count_distance_from_rear(t_stack st, unsigned int element_idx)
// {
// 	unsigned int	distance_end;
// 	unsigned int	prev;

// 	distance_end = 0;
// 	prev = st.rear;
// 	while (prev != element_idx)
// 	{
// 		distance_end++;
// 		prev = prev_idx(st, prev);
// 	}
// 	return (distance_end);
// }

void	count_rb_or_rrb(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx)
{
	unsigned int	index_b;

	index_b = count_distance_from_front(ps->b, element_idx);
	if (index_b <= ps->b.size / 2)
		cost->rb = index_b;
	else
		cost->rrb = ps->b.size - index_b;
}

unsigned int	get_index_a(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx)
{
	unsigned int	index_a;
	unsigned int	next;
	unsigned int	prev;
	unsigned int	index_a_rev;

	index_a = 0;
	next = ps->a.front;
	while (ps->b.elements[element_idx] > ps->a.elements[next])
	{
		index_a++;
		next = next_idx(ps->a, next);
	}
	index_a_rev = 0;
	prev = ps->a.rear;
	while (ps->b.elements[element_idx] < ps->a.elements[prev])
	{
		index_a_rev++;
		prev = prev_idx(ps->a, prev);
		index_a = ps->a.size - index_a_rev;
	}
	return (index_a);
}

void	count_ra_or_rra(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx)
{
	unsigned int	index_a;

	index_a = get_index_a(cost, ps, element_idx);
	if (index_a <= ps->a.size / 2)
		cost->ra = index_a;
	else
		cost->rra = ps->a.size - index_a;
}
