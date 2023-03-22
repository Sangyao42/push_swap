/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:46:51 by sawang            #+#    #+#             */
/*   Updated: 2023/03/22 22:19:12 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_by_pivot(t_push_swap *ps)
{
	unsigned int	pivot[2];
	unsigned int	i;

	pivot[0] = (ps->a.max_size - 1) / 2;
	pivot[1] = (ps->a.max_size - 1) * 3 / 4;
	i = 0;
	while (i < ps->a.max_size)
	{
		if (ps->a.elements[ps->a.front] >= pivot[1])
			run_command(RA, ps);
		else if (ps->a.elements[ps->a.front] < pivot[1] && \
			ps->a.elements[ps->a.front] >= pivot[0])
			run_command(PB, ps);
		else if (ps->a.elements[ps->a.front] < pivot[1])
		{
			run_command(PB, ps);
			if (ps->b.elements[ps->b.front] < \
				ps->b.elements[next_idx(ps->b, ps->b.front)])
				run_command(RB, ps);
		}
		i++;
	}
	while (ps->a.size > 3)
		run_command(PB, ps);
	sort_small_nums(ps);
}
