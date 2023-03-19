/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_getter_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:27:41 by sawang            #+#    #+#             */
/*   Updated: 2023/03/17 18:13:23 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	flip_tri_shape(char *tri_shape, int tri_amount)
{
	int	i;
	int	temp;

	i = 0;
	while (i < tri_amount / 2)
	{
		temp = tri_shape[i];
		tri_shape[i] = tri_shape[tri_amount - 1 - i];
		tri_shape[tri_amount - 1 - i] = temp;
		i++;
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

static void	tri_getter(t_tri *tri_info, int *tri_priority)
{
	tri_info->tri_shape = get_tri_shape(tri_info->tri_amount);
	tri_info->tri_size = \
		get_tri_size(tri_priority, tri_info->max_size, tri_info->tri_amount);
	flip_tri_shape(tri_info->tri_shape, tri_info->tri_amount);
	flip_tri_size(tri_info->tri_size, tri_info->tri_amount);
}

void	init_tri(t_tri *tri_info)
{
	tri_info->max_size = 0;
	tri_info->tri_amount = 0;
	tri_info->tri_shape = NULL;
	tri_info->tri_size = NULL;
}

int	main(void)
{
	int		*tri_priority;
	t_tri	tri_info;

	init_tri(&tri_info);
	tri_info.max_size = 17;
	tri_info.tri_amount = triangle_counter(tri_info.max_size);
	printf ("tri_amount:%d with total elements %d\n", tri_info.tri_amount, tri_info.max_size);
	tri_priority = get_tri_priority(tri_info.tri_amount);
	printf_tri_priority(tri_priority, tri_info.tri_amount);
	tri_getter(&tri_info, tri_priority);
	printf("shape is %s with size %zu\n", tri_info.tri_shape, ft_strlen(tri_info.tri_shape));
	printf_tri_size(tri_info.tri_size, tri_info.tri_amount);
	if (tri_priority)
		free(tri_priority); // Is priority needed afterwards? If not, free it in get_tri_size().
	int	i = 0;
	while (tri_info.tri_amount > 1)
	{
		i++;
		tri_merger(tri_info.tri_shape, tri_info.tri_size, &(tri_info.tri_amount));
		printf("after %d-th merge, tri_amount is %d\n", i, tri_info.tri_amount);
		printf("after %d-th merge, tri_shape is %s\n", i, tri_info.tri_shape);
		printf_tri_size(tri_info.tri_size, tri_info.tri_amount);
	}
	if (tri_info.tri_shape)
	{
		free(tri_info.tri_shape);
		tri_info.tri_shape = NULL;
	}
	if (tri_info.tri_size)
	{
		free(tri_info.tri_size);
		tri_info.tri_size = NULL;
	}
	return (0);
}

void	get_triangle(t_tri tri_info)
{

}
