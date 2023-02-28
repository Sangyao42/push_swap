/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:02:54 by sawang            #+#    #+#             */
/*   Updated: 2023/02/28 16:03:20 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_empty(t_stack st)
{
	if (st.size == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	is_sorted(t_stack st)
{
	unsigned int	i;
	unsigned int	idx;
	unsigned int	next;

	i = 1;
	idx = st.front;
	while (i < st.max_size)
	{
		next = next_idx(st, idx);
		if (st.elements[idx] > st.elements[next])
			return (EXIT_FAILURE);
		idx = next;
		i++;
	}
	return (EXIT_SUCCESS);
}
