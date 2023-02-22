/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:33:29 by sawang            #+#    #+#             */
/*   Updated: 2023/02/22 17:34:26 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_is_non_digit(char c)
{
	if (c > '9' || c < '0')
		return (1);
	else
		return (0);
}

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

int	ps_atoi(const char *str)
{
	int			sign;
	long long	value;

	sign = 1;
	while (is_non_space(*str) == 1)
		str = str + 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str = str + 1;
	}
	value = 0;
	while (*str != '\0' && ('0' <= *str && *str <= '9'))
	{
		value = 10 * value;
		value = value + (*str - '0');
		if ((value * sign) > INT_MAX || (value * sign) < INT_MIN)
			return (1);
		str++;
	}
	return ((int) value * sign);
}
