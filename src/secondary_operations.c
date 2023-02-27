/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:43:21 by sawang            #+#    #+#             */
/*   Updated: 2023/02/27 16:39:47 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_push_swap *ps)
{
	swap(&(ps->a));
	swap(&(ps->b));
}

void	rr(t_push_swap *ps)
{
	rotate(&(ps->a), FRONT);
	rotate(&(ps->b), FRONT);
}

void	rrr(t_push_swap *ps)
{
	rotate(&(ps->a), END);
	rotate(&(ps->b), END);
}


