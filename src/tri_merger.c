/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_merger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:58:41 by sawang            #+#    #+#             */
/*   Updated: 2023/03/09 16:16:41 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_merger(char *tri_shape, int *tri_size, unsigned int *tri_amount)
{
	int	new_tri_amount;
	int	last;
	int	i;

	new_tri_amount = *tri_amount / 3;
	last = *tri_amount;
	tri_shape[new_tri_amount] = '\0';
	i = 0;
	while (i < new_tri_amount)
	{
		tri_size[i] = tri_size[i] + tri_size[last - 1] + \
			tri_size[last - 1 - new_tri_amount];
		i++;
		last--;
	}
	*tri_amount = new_tri_amount;
}
