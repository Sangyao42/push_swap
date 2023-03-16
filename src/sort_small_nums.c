/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_nums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:52:25 by sawang            #+#    #+#             */
/*   Updated: 2023/03/16 22:58:16 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_nums(t_push_swap *ps, t_command **cmd)
{
	int	a;
	int	b;
	int	c;

	a = ps->a.elements[ps->a.front];
	b = ps->a.elements[next_idx(ps->a, ps->a.front)];
	c = ps->a.elements[ps->a.rear];
	if (a > b && a < c && b < c)
		add_command(SA, cmd);
	else if (a > b && a > c && b > c)
	{
		add_command(SA, cmd);
		add_command(RRA, cmd);
	}
	else if (a > b && a > c && b < c)
		add_command(RA, cmd);
	else if (a < b && a < c && b > c)
	{
		add_command(SA, cmd);
		add_command(RA, cmd);
	}
	else if (a < b && a > b && b > c)
		add_command(RRA, cmd);
}

void	sort_4_nums(t_push_swap *ps, t_command **cmd)
{
	int	min;

	min = get_min_num(ps->a.elements);
	while (ps->a.elements[ps->a.front] != min)
		add_command(RA, cmd);
	add_command(PB, cmd);
	sort_3_nums(ps, cmd);
	add_command(PA, cmd);
}

void	sort_5_nums(t_push_swap *ps, t_command **cmd)
{
	int	min;
	int	max;
	int	cnt;



	
	cnt = 0;
	while (cnt < 2)
	{
		while (ps->a.elements[ps->a.front] != min && \
			ps->a.elements[ps->a.front] != max)
			add_command(RA, cmd);
		add_command(PB, cmd);
		cnt++;
	}
	if (ps->b.elements[ps->b.front] < ps->b.elements[ps->b.rear])
		add_command(SB, cmd);
	sort_3_nums(ps, cmd);
	add_command(PA, cmd);
	add_command(RA, cmd);
	add_command(PA, cmd);
}
