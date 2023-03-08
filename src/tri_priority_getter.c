/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_priority_getter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:22:21 by sawang            #+#    #+#             */
/*   Updated: 2023/03/08 18:32:03 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_tri_priority(int tri_amount)
{
	int	priority;
	int	layer;
	int	tri_index;
	int	*tri_priority;

	tri_priority = (int *)ft_calloc(tri_amount, sizeof(int));
	if (!tri_priority)
		return (NULL);
	tri_index = 0;
	while (tri_index < tri_amount)
	{
		layer = 1;
		priority = 0;
		while ((tri_index / layer) % 3 == 1)
		{
			priority += 1;
			layer *= 3;
		}
		tri_priority[tri_index] = priority;
		tri_index++;
	}
	return (tri_priority);
}

int	get_max_priority(int *tri_priority, int tri_amount)
{
	int	max;
	int	i;

	i = 0;
	max = 0;
	while (i < tri_amount)
	{
		if (tri_priority[i] > max)
			max = tri_priority[i];
		i++;
	}
	return (max);
}
