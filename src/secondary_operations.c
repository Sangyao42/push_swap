/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:43:21 by sawang            #+#    #+#             */
/*   Updated: 2023/02/23 14:47:46 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_push_swap ps)
{
	swap(ps.a);
	swap(ps.b);
}

void	rr(t_push_swap ps)
{
	rotate(ps.a, FRONT);
	rotate(ps.b, FRONT);
}

void	rrr(t_push_swap ps)
{
	rotate(ps.a, END);
	rotate(ps.b, END);
}

void	command(struct s_push_swap ps, char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 4) == 0)
		push(ps.a, ps.b);
	if (ft_strncmp(cmd, "pb\n", 4) == 0)
		push(ps.b, ps.a);
	if (ft_strncmp(cmd, "sa\n", 4) == 0)
		swap(ps.a);
	if (ft_strncmp(cmd, "sb\n", 4) == 0)
		swap(ps.b);
	if (ft_strncmp(cmd, "ss\n", 4) == 0)
		ss(ps);
	if (ft_strncmp(cmd, "ra\n", 4) == 0)
		rotate(ps.a, FRONT);
	if (ft_strncmp(cmd, "rb\n", 4) == 0)
		rotate(ps.b, FRONT);
	if (ft_strncmp(cmd, "rr\n", 4) == 0)
		rr(ps);
	if (ft_strncmp(cmd, "rra\n", 5) == 0)
		rotate(ps.a, END);
	if (ft_strncmp(cmd, "rrb\n", 5) == 0)
		rotate(ps.b, END);
	if (ft_strncmp(cmd, "rrr\n", 5) == 0)
		rrr(ps);
	else
		ft_putstr_fd("Error\n", 2); // 명령어를 찾을 수 없는 경우
	// exit(-1);
}
