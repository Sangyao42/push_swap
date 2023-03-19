/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_nums_sorter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:41:19 by sawang            #+#    #+#             */
/*   Updated: 2023/03/19 18:54:05 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_nums(t_push_swap *ps)
{
	index_input(ps);
	partition_input(ps, a to b);
	push_back_to_a(ps);
}

push_back_b(ps)
{
	get index of the best in b; 
	index = least_cost(stack b);
	n_rb_or_rrb = least_cost.rb_or_rrb;
		get how many ra or rra needed from least_cost
	n_ra_or_rra = least_cost.ra_or_rra;
	if ()
	execute_insertion(least_cost);
	push(b, a);
}


execute_insertion(least_cost)
{
	if (least_cost. ra < least_cost.rra && least_cost.rb < least_cost.rrb)
	{
		while (ra > 0 && rb > 0)
		{
			rr(ps);
			ra--;
			rb--;
		}
		while(ra>0)
		{
			rotate(a);
			ra--;
		}
		while(rb>0)
		{
			rotate(b);
			rb--;
		}
	}
	else if (least_cost. ra > least_cost.rra && least_cost.rb > least_cost.rrb)
	{
		while (rra > 0 && rrb > 0)
		{
			rrr(ps);
			rra--;
			rrb--;
		}
		while(rra>0)
		{
			rotate(a);
			rra--;
		}
		while(rrb>0)
		{
			rotate(b);
			rrb--;
		}
	}
	else if (least_cost. rb < least_cost.rrb)
	{
		while(rb > 0)
		{
			rotate(b);
			rb--;
		}
		if(ra < rra)
		{
			ra until ra == 0;
		}
		else
			rra until rra == 0;
	}
	else if (rb > rrb)
	{
		rrb until rrb ==0;
		if(ra < rra)
		{
			ra until ra == 0;
		}
		else
			rra until rra == 0;
	}




}



