/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_getter_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:27:41 by sawang            #+#    #+#             */
/*   Updated: 2023/03/08 22:55:11 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_tri_priority(int	*tri_priority, int tri_amount);
void	printf_tri_size(int *tri_size, int tri_amount);

int	main(void)
{
	int		assume_maxsize;
	int		tri_amount;
	char	*shape;
	int		*tri_priority;
	int		*tri_size;

	assume_maxsize = 301;
	tri_amount = triangle_counter(assume_maxsize);
	printf ("tri_amount:%d with total elements %d\n", tri_amount, assume_maxsize);
	shape = get_tri_shape(tri_amount);
	printf("shape is %s with size %zu\n", shape, ft_strlen(shape));
	if (shape)
		free(shape);
	tri_priority = get_tri_priority(tri_amount);
	printf_tri_priority(tri_priority, tri_amount);
	tri_size = get_tri_size(tri_priority, assume_maxsize, tri_amount);
	printf_tri_size(tri_size, tri_amount);
	if (tri_priority)
		free(tri_priority);
	if (tri_size)
		free(tri_size);
	return (0);
}
