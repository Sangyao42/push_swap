/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:02:26 by sawang            #+#    #+#             */
/*   Updated: 2023/03/08 18:15:28 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	printf_tri_priority(int	*tri_priority, int tri_amount)
{
	int	i;

	i = 0;
	printf("tri_priority is ");
	while (i < tri_amount)
	{
		printf("%d", tri_priority[i]);
		i++;
	}
	printf(" with size %d\n", tri_amount);
}

void	printf_tri_size(int *tri_size, int tri_amount)
{
	int	i;
	int	total_elements;

	i = 0;
	total_elements = 0;
	printf("tri_size is \n");
	while (i < tri_amount)
	{
		total_elements += tri_size[i];
		printf("%d-th tri_size %d\t", i, tri_size[i]);
		i++;
	}
	printf(" with total elements %d\n", total_elements);
}
