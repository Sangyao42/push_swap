/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pri_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:01:17 by sawang            #+#    #+#             */
/*   Updated: 2023/02/21 17:57:32 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*deque(t_stack *st, enum e_rear rear)
{
	t_node	*node;

	node = st->node[rear];
	if (st->size == 1)
	{
		st->node[0] = NULL;
		st->node[1] = NULL;
	}
	else if (rear == 0)
	{
		st->node[0] = st->node[0]->next;
		st->node[0]->prev = NULL;
		node->next = NULL;
	}
	else if (rear == 1)
	{
		st->node[1] = st->node[1]->prev;
		st->node[1]->next = NULL;
		node->prev = NULL;
	}
	// if (st->size == 2)
	// 	st->node[1 - rear] = st->node[rear];
	st->size--;
	return (node);
}

// static t_node	*deque(t_stack *st, enum e_rear rear)
// {
// 	t_node	*node;

// 	node = st->node[rear];
// 	if (st->size == 1)
// 	{
// 		st->node[0] = NULL;
// 		st->node[1] = NULL;
// 	}
// 	else
// 	{
// 		if (rear == 0)
// 		{
// 			st->node[0] = st->node[0]->next;
// 			(*st->node[0]).prev = NULL;
// 			node->next = NULL;
// 		}
// 		else
// 		{
// 			st->node[1] = st->node[1]->prev;
// 			(*st->node[1]).next = NULL;
// 			node->prev = NULL;
// 		}
// 	}
// 	if (st->size == 2)
// 		st->node[!rear] = st->node[rear];
// 	st->size--;
// 	return (node);
// }

// static void	enque(t_stack *st, enum e_rear rear, t_node *node)
// {
// 	if (st->size == 0)
// 	{
// 		st->node[0] = node;
// 		st->node[1] = NULL;
// 	}
// 	else if (st->size == 1)
// 	{
// 		st->node[1] = node;
// 		st->node[1]->prev = st->node[0];
// 		st->node[0]->next = st->node[1];
// 	}
// 	else if (rear == 0)
// 	{
// 		node->next = st->node[0];
// 		st->node[0]->prev = node;
// 		st->node[0] = node;
// 	}
// 	else if (rear == 1)
// 	{
// 		node->prev = st->node[1];
// 		st->node[1]->next = node;
// 		st->node[1] = node;
// 	}
// 	st->size++;
// }

static void	enque(t_stack *st, enum e_rear rear, t_node *node)
{
	if (st->size == 0)
	{
		st->node[0] = node;
		st->node[1] = node;
	}
	else if (st->size == 1)
	{
		st->node[rear] = node;
		st->node[1]->prev = st->node[0];
		st->node[0]->next = st->node[1];
	}
	else if (rear == 0)
	{
			node->next = st->node[0];
			st->node[0]->prev = node;
			st->node[0] = node;
	}
	else if (rear == 1)
	{
			node->prev = st->node[1];
			st->node[1]->next = node;
			st->node[1] = node;
	}
	st->size++;
}

void	push(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (from->size < 1)
		return ;
	node = deque(from, FRONT);
	enque(to, FRONT, node);
}

void	swap(t_stack *st)
{
	t_node	*temp1;
	t_node	*temp2;

	if (st->size < 2)
		return ;
	temp1 = deque(st, FRONT);
	temp2 = deque(st, FRONT);
	enque(st, FRONT, temp1);
	enque(st, FRONT, temp2);
}

void	rotate(t_stack *st, enum e_rear rear)
{
	t_node	*node;

	if (st->size < 2)
		return ;
	node = deque(st, rear);
	enque(st, !rear, node);
}
