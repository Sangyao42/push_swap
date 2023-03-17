/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:42:48 by sawang            #+#    #+#             */
/*   Updated: 2023/03/17 15:45:33 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	// t_command	*cmd;

	init_ps(&ps, argc, argv);
	// init_cmd(&cmd);
	if (ps.a.max_size < 6)
	{
		sort_small_nums(&ps);
		//print_cmd(); //free_cmd linked list
		free_ps(&ps);
		return (EXIT_SUCCESS);
	}
	sort_large_nums(&ps);
	free_ps(&ps);
	//free triangle shape triangle size and triangle priority
	//free command linked list
	return (EXIT_SUCCESS);
}
