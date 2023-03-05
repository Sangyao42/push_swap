/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tri_shape.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 19:19:51 by sawang            #+#    #+#             */
/*   Updated: 2023/03/05 22:29:24 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

// size_t	ft_strlcpy(char *dest, const char *src, size_t dessize)
// {
// 	size_t	src_len;
// 	size_t	i;

// 	src_len = 0;
// 	i = 0;
// 	while (src[src_len] != '\0')
// 		src_len++;
// 	if (dessize != 0)
// 	{
// 		while (src[i] != '\0' && i < dessize -1)
// 		{
// 			dest[i] = src[i];
// 			i++;
// 		}
// 		dest[i] = '\0';
// 	}
// 	return (src_len);
// }

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

char	*str_rev(char *str)
{
	int		i;
	char	*rev_str;
	size_t	len;

	rev_str = str;
	len = ft_strlen(str);
	i = 0;
	while (str[i])
	{
		if (str[i] == 'D')
			rev_str[len - 1 - i] = 'A';
		else if (str[i] == 'A')
			rev_str[len - 1 - i] = 'D';
		i++;
	}
	return (rev_str);
}

char	*get_tri(int tri_size)
{
	char	*shape;
	char	*str_prev;

	shape = malloc(tri_size * sizeof(char) + 1);
	if (!shape)
		return (NULL);
	shape[tri_size] = '\0';
	if (tri_size == 1)
		shape[0] = 'A';
	else if (tri_size == 3)
		// ft_strlcpy(shape, "DDA", 4);
		ps_strlcpy(shape, "DDA", 3);
	else if (tri_size / 3 >= 3)
	{
		str_prev = get_tri(tri_size / 3);
		// printf("%d %s\n", tri_size / 3, shape);
		ps_strlcpy(shape + (2 * tri_size / 3), str_prev, tri_size / 3);
		ps_strlcpy(shape, str_rev(str_prev), tri_size / 3);
		free(str_prev);
		ps_strlcpy(shape + (tri_size / 3), shape, tri_size / 3);
	}
	return (shape);
}

int	main(void)
{
	int		assume_maxsize;
	int		tri_size;
	char	*shape;
	int		n;
	int 	i;

	assume_maxsize = 80;
	tri_size = assume_maxsize / 3;
	i = 0;
	while (i < n)
	{
		
		i++;
	}

	printf ("tri_size:%d\n", tri_size);
	shape = get_tri(tri_size);
	printf("shape is %s\n", shape);
	if (shape)
		free(shape);
	return (0);
}
