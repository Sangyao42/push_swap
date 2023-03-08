/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_size_getter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:19:16 by sawang            #+#    #+#             */
/*   Updated: 2023/03/08 22:54:53 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_tri(int *tri_size, int *max_size, int tri_amount)
{
	int	i;

	i = 0;
	if (*max_size == 1)
	{
		tri_size[i] = *max_size;
		*max_size = 0;
		// return (max_size);
	}
	while (i < tri_amount)
	{
		tri_size[i] = 2;
		i++;
		*max_size -= 2;
	}
	// return (max_size);
}

static void	fill_tri_prior(int *size, int *prior, int *max_size, int tri_n)
{
	int	i;
	int	max_prior;

	max_prior = get_max_priority(prior, tri_n);
	while (max_prior > 0 && *max_size > 0)
	{
		i = 0;
		while (i < tri_n)
		{
			if (prior[i] == max_prior && size[i] < 6 && *max_size >= 4)
			{
				size[i] += 4;
				// prior[i] = 0;
				(*max_size) -= 4;
			}
			if (prior[i] == max_prior && size[i] < 6 && *max_size < 4)
			{
				size[i] += *max_size;
				*max_size = 0;
			}
			// printf("tri_size in test: %d\n", size[i]);
			i++;
		}
		max_prior--;
	}
}

static void	fill_tri_rest(int *tri_size, int *max_size, int tri_amount)
{
	int	i;

	while (*max_size > 0)
	{
		i = 0;
		while (i < tri_amount && *max_size > 0)
		{
			if (tri_size[i] < 6)
			{
				tri_size[i]++;
				(*max_size)--;
			}
			i++;
		}
	}
}

static void	flip_tri_size(int *tri_size, int tri_amount)
{
	int	i;
	int	temp;

	i = 0;
	while (i < tri_amount / 2)
	{
		temp = tri_size[i];
		tri_size[i] = tri_size[tri_amount - 1 - i];
		tri_size[tri_amount - 1 - i] = temp;
		i++;
	}
}

int	*get_tri_size(int *tri_priority, int max_size, int tri_amount)
{
	int	*tri_size;

	if (!tri_priority)
		return (NULL);
	tri_size = (int *)ft_calloc(tri_amount, sizeof(int));
	if (!tri_size)
		return (NULL);
	init_tri(tri_size, &max_size, tri_amount);
	// printf("mid_test: ");
	// printf_tri_size(tri_size, tri_amount);
	// printf("mid max_priority is %d\tmax_size is %d\n", max_priority, max_size);
	fill_tri_prior(tri_size, tri_priority, &max_size, tri_amount);
	// printf("max_size in test: %d\n", max_size);
	fill_tri_rest(tri_size, &max_size, tri_amount);
	flip_tri_size(tri_size, tri_amount);
	return (tri_size);
}
