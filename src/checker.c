/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:03:32 by sawang            #+#    #+#             */
/*   Updated: 2023/03/24 15:17:43 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_push_swap ps); //for testing

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	init_ps(&ps, argc, argv);
	// print_stacks(ps);
	if (command_checker(&ps))
	{
		free_ps(&ps);
		// system("leaks checker");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (is_sorted(ps.a) == EXIT_SUCCESS && \
			stack_is_empty(ps.b) == EXIT_SUCCESS)
			ft_putstr_fd("OK\n", STDOUT_FILENO);
		else
			ft_putstr_fd("KO\n", STDOUT_FILENO);
	}
	free_ps(&ps);
	// system("leaks checker");
	exit(EXIT_SUCCESS);
}
