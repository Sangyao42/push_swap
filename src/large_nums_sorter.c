/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_nums_sorter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:37:35 by sawang            #+#    #+#             */
/*   Updated: 2023/03/17 18:13:14 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_nums(t_push_swap *ps)
{
	tri_info;
	get_triangle();
	form_trianle();
	while (!is_sorted(a) && !stack_is_empty(b))
	{
		merge_stack(ps, tri_info);
	}
}

void	merge_stack(ps, tri_info)
{
	one_third_need_to_push(tri_info);
	push(ps,tri_info);// while loop
	merge_into_one_third(ps, tri_info);
}
