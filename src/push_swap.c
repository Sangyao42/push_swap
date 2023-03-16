/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:42:48 by sawang            #+#    #+#             */
/*   Updated: 2023/03/16 15:57:18 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*elements;

	// if (argc < 2)
	// 	ft_putstr_fd(2, "Error\n");
	// else if (argc == 2)
	// 	input = ft_split((*argv + 1));
	// else
	// 	input = argv;
	// if (input_is_valid(argc - 1, input))
	// 	return (1);
	// elements = get_input(argc, argv);
	// if (!elements)
	// 	exit(EXIT_FAILURE);
	// free(elements);

	t_push_swap ps;
	init_ps(&ps, argc, argv);
	if (ps.a.max_size < 6)
	{
		sort_small_nums(&ps);
		free_ps(&ps);
		return (EXIT_SUCCESS);
	}
	sort_large_nums(&ps);
	free_ps(&ps);
	//free triangle shape triangle size and triangle priority
	//free command linked list
	return (EXIT_SUCCESS);
}
