/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:01:18 by sawang            #+#    #+#             */
/*   Updated: 2023/03/02 15:30:30 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	command_checker(t_push_swap *ps)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (command(ps, cmd) == 1)
		{
			ft_putstr_fd("Operations Error\n", 2);
			free(cmd);
			return (EXIT_FAILURE);
		}
		print_stacks(*ps);
		free(cmd);
		cmd = get_next_line(0);
	}
	return (EXIT_SUCCESS);
}

int	command(t_push_swap *ps, char *cmd)
{
	if (ps_strcmp(cmd, "pa\n") == 0)
		push(&(ps->b), &(ps->a));
	else if (ps_strcmp(cmd, "pb\n") == 0)
		push(&(ps->a), &(ps->b));
	else if (ps_strcmp(cmd, "sa\n") == 0)
		swap(&(ps->a));
	else if (ps_strcmp(cmd, "sb\n") == 0)
		swap(&(ps->b));
	else if (ps_strcmp(cmd, "ss\n") == 0)
		ss(ps);
	else if (ps_strcmp(cmd, "ra\n") == 0)
		rotate(&(ps->a), FRONT);
	else if (ps_strcmp(cmd, "rb\n") == 0)
		rotate(&(ps->b), FRONT);
	else if (ps_strcmp(cmd, "rr\n") == 0)
		rr(ps);
	else if (ps_strcmp(cmd, "rra\n") == 0)
		rotate(&(ps->a), END);
	else if (ps_strcmp(cmd, "rrb\n") == 0)
		rotate(&(ps->b), END);
	else if (ps_strcmp(cmd, "rrr\n") == 0)
		rrr(ps);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
