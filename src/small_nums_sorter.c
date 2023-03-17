/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_nums_sorter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:52:25 by sawang            #+#    #+#             */
/*   Updated: 2023/03/17 19:06:43 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_nums(t_push_swap *ps)
{
	if (ps->a.elements[ps->a.front] > ps->a.elements[ps->a.rear])
		add_command(SA);
}

void	sort_3_nums(t_push_swap *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->a.elements[ps->a.front];
	b = ps->a.elements[next_idx(ps->a, ps->a.front)];
	c = ps->a.elements[ps->a.rear];
	if (a > b && a < c && b < c)
		// add_command(SA);
		swap(&ps->a);
	else if (a > b && a > c && b > c)
	{
		add_command(SA);
		add_command(RRA);
	}
	else if (a > b && a > c && b < c)
		add_command(RA);
	else if (a < b && a < c && b > c)
	{
		add_command(SA);
		add_command(RA);
	}
	else if (a < b && a > b && b > c)
		add_command(RRA);
}

void	sort_4_nums(t_push_swap *ps)
{
	int	min;

	min = get_min_num(ps->a.elements, ps->a.size);
	while (ps->a.elements[ps->a.front] != min)
		add_command(RA);
	add_command(PB);
	sort_3_nums(ps);
	add_command(PA);
}

void	sort_5_nums(t_push_swap *ps)
{
	int	min;
	int	max;
	int	cnt;

	min = get_min_num(ps->a.elements, ps->a.size);
	max = get_max_num(ps->a.elements, ps->a.size);
	cnt = 0;
	while (cnt < 2)
	{
		while (ps->a.elements[ps->a.front] != min && \
			ps->a.elements[ps->a.front] != max)
			add_command(RA);
		add_command(PB);
		cnt++;
	}
	if (ps->b.elements[ps->b.front] < ps->b.elements[ps->b.rear])
		add_command(SB);
	sort_3_nums(ps);
	add_command(PA);
	add_command(RA);
	add_command(PA);
}

void	sort_small_nums(t_push_swap *ps)
{
	if (ps->a.max_size == 2)
		sort_2_nums(ps);
	else if (ps->a.max_size == 3)
		sort_3_nums(ps);
	else if (ps->a.max_size == 4)
		sort_4_nums(ps);
	else if (ps->a.max_size == 5)
		sort_5_nums(ps);
}
