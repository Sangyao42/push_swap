/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:01:17 by sawang            #+#    #+#             */
/*   Updated: 2023/02/23 12:55:35 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack from, t_stack to)
{
	if (from.size < 1)
		return ;
	enque(to, FRONT, deque(from, FRONT));
}

void	swap(t_stack st)
{
	int	temp1;
	int	temp2;

	if (st.size < 2)
		return ;
	temp1 = deque(st, FRONT);
	temp2 = deque(st, FRONT);
	enque(st, FRONT, temp1);
	enque(st, FRONT, temp2);
}

void	rotate(t_stack st, t_rear rear)
{
	if (st.size < 2)
		return ;
	enque(st, !rear, deque(st, rear));
}
