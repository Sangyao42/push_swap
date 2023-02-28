/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:00:06 by sawang            #+#    #+#             */
/*   Updated: 2023/02/28 16:01:54 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_ps(t_push_swap *ps)
{
	free(ps->a.elements);
	ps->a.elements = NULL;
	free(ps->b.elements);
	ps->b.elements = NULL;
	return ;
}
