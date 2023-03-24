/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:24:46 by sawang            #+#    #+#             */
/*   Updated: 2023/03/24 14:52:15 by sawang           ###   ########.fr       */
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

t_cmd_cost	get_best_commands(t_push_swap *ps)
{
	t_cmd_cost		best;
	unsigned int	next;
	t_cmd_cost		temp_cost;
	unsigned int	i;

	init_cmd_cost(&best);
	update_cmd_cost(&best, ps, ps->b.front);
	i = 1;
	next = next_idx(ps->b, ps->b.front);
	while (i < ps->b.size)
	{
		init_cmd_cost(&temp_cost);
		update_cmd_cost(&temp_cost, ps, next);
		if (temp_cost.cmd_cost < best.cmd_cost)
			best = temp_cost;
		next = next_idx(ps->b, next);
		i++;
	}
	return (best);
}

void	update_cmd_cost(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx)
{
	count_rb_or_rrb(cost, ps, element_idx);
	count_ra_or_rra(cost, ps, element_idx);
	while (cost->ra && cost->rb)
	{
		cost->rr++;
		cost->ra--;
		cost->rb--;
	}
	while (cost->rra && cost->rrb)
	{
		cost->rrr++;
		cost->rra--;
		cost->rrb--;
	}
	cost->cmd_cost = cost->ra + cost->rb + cost->rr + \
		cost->rra + cost->rrb + cost->rrr;
}

void	count_rb_or_rrb(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx)
{
	unsigned int	index_b;

	index_b = get_index_b(ps->b, element_idx);
	if (index_b <= ps->b.size / 2)
		cost->rb = index_b;
	else
		cost->rrb = ps->b.size - index_b;
}

void	count_ra_or_rra(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx)
{
	unsigned int	index_a;

	index_a = 0;
	if (is_sorted(ps->a) == EXIT_SUCCESS)
		index_a = get_index_a_is_sorted(ps, element_idx);
	else
	{
		if (ps->b.elements[element_idx] > ps->a.elements[ps->a.front])
			index_a = get_index_ra(ps, element_idx);
		else
			index_a = get_index_rra(ps, element_idx);
	}
	if (index_a <= ps->a.size / 2)
		cost->ra = index_a;
	else
		cost->rra = ps->a.size - index_a;
}
