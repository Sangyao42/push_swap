/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:38:26 by sawang            #+#    #+#             */
/*   Updated: 2023/02/27 17:38:39 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_stack
{
	int				*elements;
	unsigned int	front;
	unsigned int	rear;
	unsigned int	size;
	unsigned int	max_size;
}			t_stack;

typedef struct s_push_swap
{
	t_stack			a;
	t_stack			b;
	unsigned int	max_size;
}				t_push_swap;

typedef enum e_rear
{
	FRONT = 0,
	END = 1,
}	t_rear;

/**
 *Function for initialize the stack
*/
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
void	get_input(int argc, char **argv, t_stack *a);
void	get_input_split(char **argv, t_stack *a);
void	get_input_argv(int argc, char **argv, t_stack *a);
//static int		*ft_atoi_input(int counter, char **input);
// Input utils
int		ps_is_non_digit(char c);
int		ps_strcmp(char *s1, char *s2);
int		ps_atoi(const char *str);

/**
 * Functions for operations
*/
// atom operations
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
 * for Checker
*/


#endif
