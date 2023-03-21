/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_nums_sorter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:52:25 by sawang            #+#    #+#             */
/*   Updated: 2023/03/21 22:30:22 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_nums(t_push_swap *ps)
{
	if (ps->a.elements[ps->a.front] > ps->a.elements[ps->a.rear])
		run_command(SA, ps);
}

void	sort_3_nums(t_push_swap *ps)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	a = ps->a.elements[ps->a.front];
	b = ps->a.elements[next_idx(ps->a, ps->a.front)];
	c = ps->a.elements[ps->a.rear];
	if (a > b && a < c && b < c)
		run_command(SA, ps);
	else if (a > b && a > c && b > c)
	{
		run_command(SA, ps);
		run_command(RRA, ps);
	}
	else if (a > b && a > c && b < c)
		run_command(RA, ps);
	else if (a < b && a < c && b > c)
	{
		run_command(SA, ps);
		run_command(RA, ps);
	}
	else if (a < b && a > c && b > c)
		run_command(RRA, ps);
}

void	sort_4_nums(t_push_swap *ps)
{
	unsigned int	min;

	min = get_min_num(ps->a.elements, ps->a.size);
	while (ps->a.elements[ps->a.front] != min)
		run_command(RA, ps);
	if (is_sorted(ps->a) == EXIT_FAILURE)
	{
		run_command(PB, ps);
		sort_3_nums(ps);
		run_command(PA, ps);
	}
}

void	sort_5_nums(t_push_swap *ps)
{
	unsigned int	min;
	unsigned int	max;
	int				cnt;

	min = get_min_num(ps->a.elements, ps->a.size);
	max = get_max_num(ps->a.elements, ps->a.size);
	cnt = 0;
	while (cnt < 2)
	{
		while (ps->a.elements[ps->a.front] != min && \
			ps->a.elements[ps->a.front] != max)
			run_command(RA, ps);
		run_command(PB, ps);
		cnt++;
	}
	if (ps->b.elements[ps->b.front] < ps->b.elements[ps->b.rear])
		run_command(SB, ps);
	sort_3_nums(ps);
	run_command(PA, ps);
	run_command(RA, ps);
	run_command(PA, ps);
}

void	sort_small_nums(t_push_swap *ps)
{
	if (ps->a.size == 2)
		sort_2_nums(ps);
	else if (ps->a.size == 3)
		sort_3_nums(ps);
	else if (ps->a.size == 4)
		sort_4_nums(ps);
	else if (ps->a.size == 5)
		sort_5_nums(ps);
}
