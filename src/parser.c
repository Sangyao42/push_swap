/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:44:34 by sawang            #+#    #+#             */
/*   Updated: 2023/02/18 22:42:24 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_is_valid(int argc, char **input)
{
	if (argc < 2)
		return (1);
	if (all_is_int(argc, **argv))
		return (1);
	if (all_is_in_range(argc, **argv))
		return (1);
	if (is_duplicate(argc, **argv))
		return (1);
	return (0);
}

int	all_is_int(int argc, char **input)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		if (is_int((*input + 1) + i))
			return (1);
		i++;
	}
	return (0);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (!*str)
		return (1);
	while (*str + i)
	{
		if (!is_digit(*str + i))
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicate(char *str, char **input)
{
	int	i;

	i = 0;
	if (!ft)
	{
		/* code */
	}


}
int	is_in_range(char *str)
{
	int	i;

	i = 0;
	while (*str + i)
	{
		if (!is_digit(*str + i))
			return (1);
		i++;
	}
	return (0);
}
}

