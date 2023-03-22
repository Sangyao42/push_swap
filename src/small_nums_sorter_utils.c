/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_nums_sorter_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:37:13 by sawang            #+#    #+#             */
/*   Updated: 2023/03/22 22:20:43 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_min_num(unsigned int *array, unsigned int size)
{
	unsigned int	min;
	unsigned int	i;

	i = 0;
	min = array[i];
	while (++i < size)
	{
		if (min > array[i])
			min = array[i];
	}
	return (min);
}

unsigned int	get_max_num(unsigned int *array, unsigned int size)
{
	unsigned int	max;
	unsigned int	i;

	i = 0;
	max = array[i];
	while (++i < size)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}
