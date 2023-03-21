/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:38:26 by sawang            #+#    #+#             */
/*   Updated: 2023/03/21 17:24:01 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_stack
{
	unsigned int	*elements;
	unsigned int	front;
	unsigned int	rear;
	unsigned int	size;
	unsigned int	max_size;
}			t_stack;

// typedef enum e_a_or_b
// {
// 	TO_A = -1,
// 	TO_B = 1,
// }			t_a_or_b;

typedef struct s_push_swap
{
	t_stack			a;
	t_stack			b;
	unsigned int	max_size;
	// unsigned int	tri_amount;
	// char			*shape;
	// char			*tri_elem;
	// t_command		*cmd;
	// t_a_or_b	to_a_or_to_b;
}				t_push_swap;

// typedef struct s_tri
// {
// 	unsigned int	max_size;
// 	unsigned int	tri_amount;
// 	char			*tri_shape;
// 	int				*tri_size;
// }				t_tri;

// typedef enum e_single_tri_shape
// {
// 	A,
// 	D,
// }			t_single_tri_shape;

typedef enum e_rear
{
	FRONT = 0,
	END = 1,
}	t_rear;

typedef enum e_cmd
{
	PA,
	PB,
	SA,
	SB,
	RA,
	RB,
	RRA,
	RRB,
	SS,
	RR,
	RRR,
}			t_cmd;

// typedef struct s_pivot
// {

// }				t_pivot;

typedef struct s_cmd_cost
{
	unsigned int	rb;
	unsigned int	rrb;
	unsigned int	ra;
	unsigned int	rra;
	unsigned int	rr;
	unsigned int	rrr;
	unsigned int	cmd_cost;
}				t_cmd_cost;

typedef struct s_command_list
{
	t_cmd					cmd_value;
	struct s_command_list	*next;
}				t_command_list;
/**
 *Function for initialize the stack
*/
void	init_ps(t_push_swap *ps, int argc, char **argv);
void	init_stack(t_stack	*a);
/**
 * Functions for checking and getting the input from command line
*/
// Checker
int		input_is_not_valid(int arg_num, char **input);
// int		is_non_int(char *str);
int		is_duplicate(char *str, char **input, int arg_num, int arg_idx);
// int		is_not_in_range(char *str);
int		is_not_valid_int(const char *str);
// Getter
// int		*get_input(int argc, char **argv);
// int		*get_input_split(char **argv);
// int		*get_input_argv(int argc, char **argv);
// void	get_input(int argc, char **argv, t_stack *a);
// void	get_input_split(char **argv, t_stack *a);
// void	get_input_argv(int argc, char **argv, t_stack *a);
void	get_input(int argc, char **argv, t_stack *a, int **input_array);
void	get_input_split(char **argv, t_stack *a, int **input_array);
void	get_input_argv(int argc, char **argv, t_stack *a, int **input_array);
//static int		*ft_atoi_input(int counter, char **input);
// Input utils
// int		ps_is_non_digit(char c);
int		ps_strcmp(char *s1, char *s2);
// int		ps_atoi(const char *str);

/**
 * Functions for operations
*/
// atom operations
int		next_idx(t_stack st, int idx);
int		prev_idx( t_stack st, int idx);
int		deque(t_stack *st, t_rear rear);
void	enque(t_stack *st, t_rear rear, int num);
// primary operations
void	push(t_stack *from, t_stack *to);
void	swap(t_stack *st);
void	rotate(t_stack *st, t_rear rear);
void	ss(t_push_swap *ps);
void	rr(t_push_swap *ps);
void	rrr(t_push_swap *ps);

/**
 * stack status
*/
int		stack_is_empty(t_stack st);
int		is_sorted(t_stack st);
void	free_ps(t_push_swap *ps);
/**
 * for Checker
*/
int		command_checker(t_push_swap *ps);
int		command(t_push_swap *ps, char *cmd);

/**
 * Functions for indexing the input
*/
void			index_input(t_stack *a, int *input_array);
unsigned int	get_index(int to_compare, int *input_array, unsigned int input_array_size);

/***
 * Functions for sorting small numbers
*/
void	sort_small_nums(t_push_swap *ps);
void	sort_2_nums(t_push_swap *ps);
void	sort_3_nums(t_push_swap *ps);
void	sort_4_nums(t_push_swap *ps);
void	sort_5_nums(t_push_swap *ps);
unsigned int	get_min_num(unsigned int *array, unsigned int size);
unsigned int	get_max_num(unsigned int *array, unsigned int size);

/**
 * Functions for sorting large numbers
*/
void	sort_large_nums(t_push_swap *ps);
void	push_back_to_a(t_push_swap *ps);
//1. Getting how many ra/rra or rb/rrb needed
//for every element in b
unsigned int	get_index_b(t_stack st, unsigned int element_idx);
void	count_rb_or_rrb(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx);
unsigned int	count_index_ra(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx);
unsigned int	count_index_rra(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx);
void	count_ra_or_rra(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx);
//2. Functions for checking the least commands
//needed for pushing one element from b to a
void	init_cmd_cost(t_cmd_cost *cost);
t_cmd_cost	get_best_commands(t_push_swap *ps);
void	update_cmd_cost(t_cmd_cost *cost, t_push_swap *ps, \
	unsigned int element_idx);
void	get_cmd_cost(t_cmd_cost *cost);


/**
 * Functions for partitioning using 2 pivots
*/
void	partition_by_pivot(t_push_swap *ps);

/**
 * Functions for running instructions and printing commands
*/
void	run_command(t_cmd cmd_value, t_push_swap *ps);
void	print_command(t_cmd cmd_value);
void	run_best_commands(t_cmd_cost best_commands, t_push_swap *ps);
/**
 * for generating initial triangle
*/
//1. for getting triangle amount
int		triangle_counter(int max_size);
//2. for getting triangle shape
char	*get_tri_shape(int tri_amount);
//3. for getting triangle size
//3.1 first get triangle priority,
//triangle should have larger size elements
int		*get_tri_priority(int tri_amount);
int		get_max_priority(int *tri_priority, int tri_amount);
//3.2 getting size according to triangle priority
int		*get_tri_size(int *tri_priority, int max_size, int tri_amount);

/**
 * for merging the triangles
*/
void	tri_merger(char *tri_shape, int *tri_size, unsigned int *tri_amount);

/**
 * printer for testing
*/
void	print_stacks(t_push_swap ps);
void	printf_tri_priority(int	*tri_priority, int tri_amount);
void	printf_tri_size(int *tri_size, int tri_amount);

#endif
