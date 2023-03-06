/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tri_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:19:51 by sawang            #+#    #+#             */
/*   Updated: 2023/03/06 15:18:59 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

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

char	*get_tri(int tri_amount)
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
		str_prev = get_tri(tri_amount / 3);
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

int	main(void)
{
	int		assume_maxsize;
	int		tri_amount;
	char	*shape;

	assume_maxsize = 17;
	tri_amount = triangle_counter(assume_maxsize);
	printf ("tri_amount:%d\n", tri_amount);
	shape = get_tri(tri_amount);
	printf("shape is %s with size %zu\n", shape, ft_strlen(shape));
	if (shape)
		free(shape);
	return (0);
}
