/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:49:58 by sawang            #+#    #+#             */
/*   Updated: 2023/03/22 17:20:01 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_command(t_cmd cmd_value, t_push_swap *ps)
{
	if (cmd_value == PA)
		push(&(ps->b), &(ps->a));
	if (cmd_value == PB)
		push(&(ps->a), &(ps->b));
	if (cmd_value == SA)
		swap(&(ps->a));
	if (cmd_value == SB)
		swap(&(ps->b));
	if (cmd_value == RA)
		rotate(&(ps->a), FRONT);
	if (cmd_value == RB)
		rotate(&(ps->b), FRONT);
	if (cmd_value == RRA)
		rotate(&(ps->a), END);
	if (cmd_value == RRB)
		rotate(&(ps->b), END);
	if (cmd_value == SS)
		ss(ps);
	if (cmd_value == RR)
		rr(ps);
	if (cmd_value == RRR)
		rrr(ps);
	print_command(cmd_value);
}

void	print_command(t_cmd cmd_value)
{
	if (cmd_value == 0)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	if (cmd_value == 1)
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	if (cmd_value == 2)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	if (cmd_value == 3)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	if (cmd_value == 4)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	if (cmd_value == 5)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	if (cmd_value == 6)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	if (cmd_value == 7)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	if (cmd_value == 8)
		ft_putstr_fd("ss\n", STDOUT_FILENO);
	if (cmd_value == 9)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
	if (cmd_value == 10)
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}

void	run_best_commands(t_cmd_cost best_commands, t_push_swap *ps)
{
	while (best_commands.rr--)
		run_command(RR, ps);
	while (best_commands.ra--)
		run_command(RA, ps);
	while (best_commands.rb--)
		run_command(RB, ps);
	while (best_commands.rrr--)
		run_command(RRR, ps);
	while (best_commands.rra--)
		run_command(RRA, ps);
	while (best_commands.rrb--)
		run_command(RRB, ps);
}
