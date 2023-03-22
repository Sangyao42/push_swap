/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:54:39 by sawang            #+#    #+#             */
/*   Updated: 2023/03/22 16:01:14 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	next_idx(t_stack st, unsigned int idx)
{
	return ((idx + 1) % st.max_size);
}

unsigned int	prev_idx( t_stack st, unsigned int idx)
{
	return ((st.max_size + (idx - 1)) % st.max_size);
}

unsigned int	deque(t_stack *st, t_rear rear)
{
	int	num;

	if (st->size == 1)
		num = st->elements[st->front];
	else
	{
		if (rear == 0)
		{
			num = st->elements[st->front];
			st->front = next_idx(*st, st->front);
		}
		if (rear == 1)
		{
			num = st->elements[st->rear];
			st->rear = prev_idx(*st, st->rear);
		}
	}
	st->size -= 1;
	return (num);
}

void	enque(t_stack *st, t_rear rear, unsigned int num)
{
	if (st->size == 0)
		st->elements[st->front] = num;
	else if (rear == 0)
	{
		st->front = prev_idx(*st, st->front);
		st->elements[st->front] = num;
	}
	else if (rear == 1)
	{
		st->rear = next_idx(*st, st->rear);
		st->elements[st->rear] = num;
	}
	st->size += 1;
	return ;
}
