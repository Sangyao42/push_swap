/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:42:48 by sawang            #+#    #+#             */
/*   Updated: 2023/03/24 14:53:50 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	if (argc < 2)
		return (EXIT_FAILURE);
	init_ps(&ps, argc, argv);
	if (is_sorted(ps.a) == EXIT_SUCCESS && stack_is_empty(ps.b) == EXIT_SUCCESS)
	{
		free_ps(&ps);
		return (EXIT_SUCCESS);
	}
	if (ps.a.max_size < 6)
	{
		sort_small_nums(&ps);
		free_ps(&ps);
		return (EXIT_SUCCESS);
	}
	sort_large_nums(&ps);
	free_ps(&ps);
	return (EXIT_SUCCESS);
}
