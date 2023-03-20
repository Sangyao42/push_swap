/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:42:48 by sawang            #+#    #+#             */
/*   Updated: 2023/03/20 19:59:23 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	// t_command	*cmd;

	init_ps(&ps, argc, argv);
	print_stacks(ps);
	// init_cmd(&cmd);
	if (is_sorted(ps.a) && stack_is_empty(ps.b))
	{
		free_ps(&ps);
		return (EXIT_SUCCESS);
	}
	if (ps.a.max_size < 6)
	{
		sort_small_nums(&ps);
		//print_cmd(); //free_cmd linked list
		free_ps(&ps);
		return (EXIT_SUCCESS);
	}
	sort_large_nums(&ps);
	free_ps(&ps);
	//free command linked list
	system("leaks push_swap");
	return (EXIT_SUCCESS);
}
