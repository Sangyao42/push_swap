/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:24:46 by sawang            #+#    #+#             */
/*   Updated: 2023/03/21 17:34:59 by sawang           ###   ########.fr       */
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
	unsigned int	terminator;

	init_cmd_cost(&best);
	init_cmd_cost(&temp_cost);
	update_cmd_cost(&best, ps, ps->b.front);
	next = next_idx(ps->b, ps->b.front);
	terminator = next_idx(ps->b, ps->b.rear);
	while (next != terminator)
	{
		update_cmd_cost(&temp_cost, ps, next);
		if (temp_cost.cmd_cost < best.cmd_cost)
			best = temp_cost;
		next = next_idx(ps->b, next);
	}
	return (best);
}

void	update_cmd_cost(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx)
{
	count_rb_or_rrb(cost, ps, element_idx);
	count_ra_or_rra(cost, ps, element_idx);
	get_cmd_cost(cost);
}

void	get_cmd_cost(t_cmd_cost *cost)
{
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
