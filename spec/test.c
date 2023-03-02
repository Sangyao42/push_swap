/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:09:53 by sawang            #+#    #+#             */
/*   Updated: 2023/03/02 16:22:28 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		command(t_push_swap *ps, char *cmd);
void	test_operations(t_push_swap *ps);
int		stack_is_empty(t_stack st);
void	print_stacks(t_push_swap ps);
int		command_checker(t_push_swap *ps);

void	init_stack(t_stack	*a)
{
	a->elements = NULL;
	a->front = 0;
	a->rear = 0;
	a->max_size = 0;
	a->size = 0;
}

void	init_ps(t_push_swap *ps, int argc, char **argv)
{
	init_stack(&(ps->a));
	init_stack(&(ps->b));
	get_input(argc, argv, &(ps->a));
	if (!ps->a.elements)
		exit(EXIT_FAILURE);
	ps->max_size = ps->a.max_size;
	ps->b.max_size = ps->a.max_size;
	ps->b.elements = (int *)ft_calloc(ps->b.max_size, sizeof(int));
	if (!ps->b.elements)
	{
		free(ps->a.elements);
		exit(EXIT_FAILURE);
	}
}

void	free_ps(t_push_swap *ps)
{
	free(ps->a.elements);
	ps->a.elements = NULL;
	free(ps->b.elements);
	ps->b.elements = NULL;
	return ;
}

int	stack_is_empty(t_stack st)
{
	if (st.size == 0)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	is_sorted(t_stack st)
{
	unsigned int	i;
	unsigned int	idx;
	unsigned int	next;

	i = 1;
	idx = st.front;
	while (i < st.max_size)
	{
		next = next_idx(st, idx);
		if (st.elements[idx] > st.elements[next])
			return (EXIT_FAILURE);
		idx = next;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_push_swap	ps;

	init_ps(&ps, argc, argv);
	print_stacks(ps);
	// test_operations(&ps);
	if (command_checker(&ps))
	{
		free_ps(&ps);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (is_sorted(ps.a) == 0 && stack_is_empty(ps.b) == 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	free_ps(&ps);
	exit(EXIT_SUCCESS);
}

// void	test_operations(t_push_swap *ps)
// {
// 	char			*cmd;

// 	cmd = get_next_line(0);
// 	while (cmd)
// 	{
// 		if (command(ps, cmd) == 0)
// 			print_stacks(*ps);
// 		free(cmd);
// 		cmd = get_next_line(0);
// 	}
// 	// if (is_sorted(ps->a) && stack_is_empty(ps->b))
// 	// 	ft_putstr_fd(1, "OK\n");
// 	// else
// 	// 	ft_putstr_fd(1, "KO\n");
// }

int	command_checker(t_push_swap *ps)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (command(ps, cmd) == 1)
		{
			ft_putstr_fd("Operations Error\n", 2); // 명령어를 찾을 수 없는 경우
			free(cmd);
			return (EXIT_FAILURE);
		}
		print_stacks(ps);
		free(cmd);
		cmd = get_next_line(0);
	}
	return (EXIT_SUCCESS);
}

int	command(t_push_swap *ps, char *cmd)
{
	if (ps_strcmp(cmd, "pa\n") == 0)
		push(&(ps->a), &(ps->b));
	else if (ps_strcmp(cmd, "pb\n") == 0)
		push(&(ps->b), &(ps->a));
	else if (ps_strcmp(cmd, "sa\n") == 0)
		swap(&(ps->a));
	else if (ps_strcmp(cmd, "sb\n") == 0)
		swap(&(ps->b));
	else if (ps_strcmp(cmd, "ss\n") == 0)
		ss(ps);
	else if (ps_strcmp(cmd, "ra\n") == 0)
		rotate(&(ps->a), FRONT);
	else if (ps_strcmp(cmd, "rb\n") == 0)
		rotate(&(ps->b), FRONT);
	else if (ps_strcmp(cmd, "rr\n") == 0)
		rr(ps);
	else if (ps_strcmp(cmd, "rra\n") == 0)
		rotate(&(ps->a), END);
	else if (ps_strcmp(cmd, "rrb\n") == 0)
		rotate(&(ps->b), END);
	else if (ps_strcmp(cmd, "rrr\n") == 0)
		rrr(ps);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	print_stacks(t_push_swap ps)
{
	unsigned int	i;
	unsigned int	idx;

	i = 0;
	idx = ps.a.front;
	printf("stack a: ");
	while (i < ps.a.size)
	{
		printf("%d\t", ps.a.elements[idx]);
		idx = next_idx(ps.a, idx);
		i++;
	}
	printf("\n");
	printf("%p, %d, %d, %d, %d\n", ps.a.elements, ps.a.front, ps.a.rear, ps.a.size, ps.a.max_size);
	i = 0;
	printf("array a: ");
	while (i < ps.a.max_size)
	{
		printf("%d\t", ps.a.elements[i]);
		i++;
	}
	printf("\n\n");
	i = 0;
	idx = ps.b.front;
	printf("stack b: ");
	while (i < ps.b.size)
	{
		printf("%d\t", ps.b.elements[idx]);
		idx = next_idx(ps.b, idx);
		i++;
	}
	printf("\n");
	printf("%p, %d, %d, %d, %d\n", ps.b.elements, ps.b.front, ps.b.rear, ps.b.size, ps.b.max_size);
	i = 0;
	printf("array b: ");
	while (i < ps.b.max_size)
	{
		printf("%d\t", ps.b.elements[i]);
		i++;
	}
	printf("\n\n");
}

