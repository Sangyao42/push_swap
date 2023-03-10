/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:42:48 by sawang            #+#    #+#             */
/*   Updated: 2023/02/23 13:16:24 by sawang           ###   ########.fr       */
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
	elements = get_input(argc, argv);
	if (!elements)
		exit(EXIT_FAILURE);
	free(elements);
	return (0);
}
