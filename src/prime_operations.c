/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prime_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:01:17 by sawang            #+#    #+#             */
/*   Updated: 2023/02/22 22:54:25 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static t_node	*deque(t_stack *st, enum e_rear rear)
// {
// 	t_node	*node;

// 	node = st->node[rear];
// 	if (st->size == 1)
// 	{
// 		st->node[0] = NULL;
// 		st->node[1] = NULL;
// 	}
// 	else if (rear == 0)
// 	{
// 		st->node[0] = st->node[0]->next;
// 		st->node[0]->prev = NULL;
// 		node->next = NULL;
// 	}
// 	else if (rear == 1)
// 	{
// 		st->node[1] = st->node[1]->prev;
// 		st->node[1]->next = NULL;
// 		node->prev = NULL;
// 	}
// 	// if (st->size == 2)
// 	// 	st->node[1 - rear] = st->node[rear];
// 	st->size--;
// 	return (node);
// }

int	next_idx(t_stack st, int idx)
{
	return ((idx + 1) % st.max_size);
}

int	prev_idx( t_stack st, int idx)
{
	return ((st.max_size + (idx - 1)) % st.max_size);
}

int	deque(t_stack st, t_rear rear)
{
	int	num;

	if (st.size == 1)
		num = st.elements[st.front];
	else if (rear == 0)
	{
		num = st.elements[st.front];
		st.front = next_idx(st, st.front);
	}
	else if (rear == 1)
	{
		num = st.elements[st.rear];
		st.rear = prev_idx(st, st.rear);
	}
	st.size -= 1;
	return (num);
}

void	enque(t_stack st, t_rear rear, int num)
{
	if (st.size == 0)
		st.elements[st.front] = num;
	else if (rear == 0)
	{
		st.front = prev_idx(st, st.front);
		st.elements[st.front] = num;
	}
	else if (rear == 1)
	{
		st.rear = next_idx(st, st.rear);
		st.elements[st.rear] = num;
	}
	st.size += 1;
	return ;
}

void	push(t_stack from, t_stack to)
{
	if (from.size < 1)
		return ;
	enque(to, FRONT, deque(from, FRONT));
}

void	swap(t_stack st)
{
	int	temp1;
	int	temp2;

	if (st.size < 2)
		return ;
	temp1 = deque(st, FRONT);
	temp2 = deque(st, FRONT);
	enque(st, FRONT, temp1);
	enque(st, FRONT, temp2);
}

void	rotate(t_stack st, enum e_rear rear)
{
	if (st.size < 2)
		return ;
	enque(st, !rear, deque(st, rear));
}

// static void	enque(t_stack *st, enum e_rear rear, t_node *node)
// {
// 	if (st->size == 0)
// 	{
// 		st->node[0] = node;
// 		st->node[1] = node;
// 	}
// 	else if (st->size == 1)
// 	{
// 		st->node[rear] = node;
// 		st->node[1]->prev = st->node[0];
// 		st->node[0]->next = st->node[1];
// 	}
// 	else if (rear == 0)
// 	{
// 			node->next = st->node[0];
// 			st->node[0]->prev = node;
// 			st->node[0] = node;
// 	}
// 	else if (rear == 1)
// 	{
// 			node->prev = st->node[1];
// 			st->node[1]->next = node;
// 			st->node[1] = node;
// 	}
// 	st->size++;
// }

// void	push(t_stack *from, t_stack *to)
// {
// 	t_node	*node;

// 	if (from->size < 1)
// 		return ;
// 	node = deque(from, FRONT);
// 	enque(to, FRONT, node);
// }

// void	swap(t_stack *st)
// {
// 	t_node	*temp1;
// 	t_node	*temp2;

// 	if (st->size < 2)
// 		return ;
// 	temp1 = deque(st, FRONT);
// 	temp2 = deque(st, FRONT);
// 	enque(st, FRONT, temp1);
// 	enque(st, FRONT, temp2);
// }

// void	rotate(t_stack *st, enum e_rear rear)
// {
// 	t_node	*node;

// 	if (st->size < 2)
// 		return ;
// 	node = deque(st, rear);
// 	enque(st, !rear, node);
// }
