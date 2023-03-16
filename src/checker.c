/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:03:32 by sawang            #+#    #+#             */
/*   Updated: 2023/03/16 15:46:31 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_push_swap ps); //for testing

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	init_ps(&ps, argc, argv);
	print_stacks(ps);
	if (command_checker(&ps))
	{
		free_ps(&ps);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (is_sorted(ps.a) == 0 && stack_is_empty(ps.b) == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	free_ps(&ps);
	exit(EXIT_SUCCESS);
}
