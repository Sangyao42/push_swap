/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_nums_sorter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:41:19 by sawang            #+#    #+#             */
/*   Updated: 2023/03/20 22:42:47 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_nums(t_push_swap *ps)
{
	partition_by_pivot(ps);
	push_back_to_a(ps);
}

// push_back_b(ps)
// {
// 	get index of the best in b;
// 	index = least_cost(stack b);
// 	n_rb_or_rrb = least_cost.rb_or_rrb;
// 		get how many ra or rra needed from least_cost
// 	n_ra_or_rra = least_cost.ra_or_rra;
// 	if ()
// 	execute_insertion(least_cost);
// 	push(b, a);
// }

void	push_back_to_a(t_push_swap *ps)
{
	unsigned int	push_back_counter;
	t_cmd_cost		best_commands;

	push_back_counter = 0;
	while (push_back_counter < ps->b.size)
	{
		best_commands = get_best_commands(ps);
		run_best_commands(best_commands, ps);
		run_command(PA, ps);
		push_back_counter++;
	}
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

void	update_cmd_cost(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx)
{
	count_rb_or_rrb(cost, ps, element_idx);
	count_ra_or_rra(cost, ps, element_idx);
	get_cmd_cost(cost);
}

t_cmd_cost	get_best_commands(t_push_swap *ps)
{
	t_cmd_cost		best;
	unsigned int	next;
	t_cmd_cost		temp_cost;

	init_cmd_cost(&best);
	init_cmd_cost(&temp_cost);
	update_cmd_cost(&best, ps, ps->b.front);
	next = next_idx(ps->b, ps->b.front);
	while (next != ps->b.front)
	{
		update_cmd_cost(&temp_cost, ps, next);
		if (temp_cost.cmd_cost < best.cmd_cost)
			best = temp_cost;
		next = next_idx(ps->b, next);
	}
	return (best);
}
