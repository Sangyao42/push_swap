/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tri_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:19:51 by sawang            #+#    #+#             */
/*   Updated: 2023/03/07 22:40:34 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

void	printf_tri_size(int *tri_size, int tri_amount);
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ps_strlcpy(char *dest, char *src, size_t srcsize)
{
	size_t	i;

	i = 0;
	while (i < srcsize)
	{
		dest[i] = src[i];
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	mem = malloc(count * size);
	if (mem)
	{
		i = 0;
		while (i < (count * size))
		{
			mem[i] = 0;
			i++;
		}
		return (mem);
	}
	return (NULL);
}

// char	*str_rev(char *str)
// {
// 	int		i;
// 	char	*rev_str;
// 	size_t	len;

// 	rev_str = str;
// 	len = ft_strlen(str);
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == 'D')
// 			rev_str[len - 1 - i] = 'A';
// 		else if (str[i] == 'A')
// 			rev_str[len - 1 - i] = 'D';
// 		i++;
// 	}
// 	return (rev_str);
// }

char	*str_mirror(char *str)
{
	size_t	i;
	size_t	len;
	char	c;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = c;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == 'D')
			str[i] = 'A';
		else if (str[i] == 'A')
			str[i] = 'D';
		i++;
	}
	return (str);
}

char	*get_tri_shape(int tri_amount)
{
	char	*shape;
	char	*str_prev;

	shape = malloc(tri_amount * sizeof(char) + 1);
	if (!shape)
		return (NULL);
	shape[tri_amount] = '\0';
	if (tri_amount == 1)
		shape[0] = 'A';
	else if (tri_amount == 3)
		ps_strlcpy(shape, "DDA", 3);
	else if (tri_amount / 3 >= 3)
	{
		str_prev = get_tri_shape(tri_amount / 3);
		ps_strlcpy(shape + (2 * tri_amount / 3), str_prev, tri_amount / 3);
		ps_strlcpy(shape, str_mirror(str_prev), tri_amount / 3);
		free(str_prev);
		ps_strlcpy(shape + (tri_amount / 3), shape, tri_amount / 3);
	}
	return (shape);
}

int	triangle_counter(int max_size)
{
	unsigned int	tri_amount;

	tri_amount = 1;
	while (max_size / (tri_amount * 6) > 0)
		tri_amount *= 3;
	return (tri_amount);
}

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

int	*get_tri_size(int *tri_priority, int max_size, int tri_amount)
{
	int	*tri_size;
	int	i;
	int	max_priority;

	tri_size = (int *)ft_calloc(tri_amount, sizeof(int));
	if (!tri_size)
		return (NULL);
	i = 0;
	while (i < tri_amount)
	{
		tri_size[i] = 2;
		i++;
	}
	printf("mid_test: ");
	printf_tri_size(tri_size, tri_amount);
	max_size -= 2 * tri_amount;
	max_priority = get_max_priority(tri_priority, tri_amount);
	printf("mid max_priority is %d\tmax_size is %d\n", max_priority, max_size);
	while (max_priority >= 0 && max_size > 0)
	{
		i = 0;
		while (i < tri_amount)
		{
			if (tri_priority[i] == max_priority && tri_size[i] < 6 && max_size >= 4)
			{
				tri_size[i] += 4;
				tri_priority[i] = 0;
				max_size -= 4;
			}
			if (tri_priority[i] == max_priority && tri_size[i] < 6 && max_size < 4)
			{
				tri_size[i] += max_size;
				max_size = 0;
			}
			// printf("tri_size in test: %d\n", tri_size[i]);
			i++;
		}
		max_priority--;
	}
	return (tri_size);
}

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
	printf("tri_size is ");
	while (i < tri_amount)
	{
		total_elements += tri_size[i];
		printf("%d", tri_size[i]);
		i++;
	}
	printf(" with total elements %d\n", total_elements);
}

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
