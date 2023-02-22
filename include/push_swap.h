/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:38:26 by sawang            #+#    #+#             */
/*   Updated: 2023/02/22 17:43:26 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_node
{
	int				nbr;
	unsigned int	idx;
	t_node			*next;
	t_node			*prev;
}				t_node;

typedef struct s_stack
{
	unsigned int	size;
	t_node			*node[2];
}				t_stack;

typedef struct s_push_swap
{
	t_stack			a;
	t_stack			b;
	unsigned int	cnt;
}				t_push_swap;

enum e_rear
{
	FRONT = 0,
	END = 1,
}	t_rear;

void	push(t_stack *from, t_stack *to);
void	swap(t_stack *st);
void	rotate(t_stack *st, enum e_rear rear);

#endif
