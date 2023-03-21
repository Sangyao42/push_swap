/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:46:51 by sawang            #+#    #+#             */
/*   Updated: 2023/03/21 19:30:40 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	partition_by_pivot(t_push_swap *ps)
{
	unsigned int	pivot[2];
	unsigned int	i;

	pivot[0] = (ps->a.max_size - 1) / 2;
	pivot[1] = (ps->a.max_size - 1) * 3 / 4;
	printf("pivot smaller: %d\n", pivot[0]);
	printf("pivot larger: %d\n", pivot[1]);
	i = 0;
	while (i < ps->a.max_size)
	{
		if (ps->a.elements[ps->a.front] > pivot[1])
			run_command(RA, ps);
		else if (ps->a.elements[ps->a.front] <= pivot[1] && \
			ps->a.elements[ps->a.front] > pivot[0])
			run_command(PB, ps);
		else if (ps->a.elements[ps->a.front] <= pivot[1])
		{
			run_command(PB, ps);
			run_command(RB, ps);
		}
		i++;
	}
	// i = 0;
	while (ps->a.size > 3)
		run_command(PB, ps);
	sort_small_nums(ps);
	print_stacks(*ps);
}
// void	get_pivot(ps)
// {}
