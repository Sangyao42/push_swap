/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_nums_sorter_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:37:13 by sawang            #+#    #+#             */
/*   Updated: 2023/03/19 22:33:17 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

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

// int	main(void)
// {
// 	int	array[5] = {2, 6, 8, 4, 7};
// 	int min = get_min_num(array, 5);
// 	int max = get_max_num(array, 5);
// 	printf("min is %d\tmax is %d\n", min, max);
// 	return (0);
// }
