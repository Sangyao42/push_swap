/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:33:29 by sawang            #+#    #+#             */
/*   Updated: 2023/02/24 19:28:36 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ps_is_non_digit(char c)
// {
// 	if (c > '9' || c < '0')
// 		return (1);
// 	else
// 		return (0);
// }

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


