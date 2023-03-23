/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:33:29 by sawang            #+#    #+#             */
/*   Updated: 2023/03/23 21:28:05 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_strcmp(char *s1, char *s2)
{
	int	i;
	int	ret_val;

	i = 0;
	ret_val = 0;
	while (s1[i] || s2[i])
	{
		ret_val = s1[i] - s2[i];
		if (ret_val != 0)
			return (ret_val);
		else
			ret_val = 0;
		i++;
	}
	return (ret_val);
}

int	*ft_atoi_input(unsigned int counter, char **input)
{
	unsigned int	i;
	int				*elements;

	elements = (int *)ft_calloc(counter, sizeof(int));
	if (!elements)
		return (NULL);
	i = 0;
	while (i < counter)
	{
		elements[i] = ft_atoi(input[i]);
		i++;
	}
	return (elements);
}
