/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_nums_sorter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:41:19 by sawang            #+#    #+#             */
/*   Updated: 2023/03/21 19:52:35 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_nums(t_push_swap *ps)
{
	partition_by_pivot(ps);
	push_back_to_a(ps);
	rotate_final(ps);
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
	t_cmd_cost		best_commands;

	while (ps->b.size)
	{
		best_commands = get_best_commands(ps);
		run_best_commands(best_commands, ps);
		run_command(PA, ps);
	}
}

void	rotate_final(t_push_swap *ps)
{
	unsigned int	front_value;
	unsigned int	rotate_cnt;

	front_value = ps->a.elements[ps->a.front];
	if (front_value <= ps->a.max_size / 2)
	{
		while (front_value--)
		{
			run_command(RRA, ps);
			// front_value--;
		}
	}
	else
	{
		rotate_cnt = ps->a.max_size - front_value;
		while (rotate_cnt--)
			run_command(RA, ps);
	}
}

