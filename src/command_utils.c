/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:02:02 by sawang            #+#    #+#             */
/*   Updated: 2023/03/17 16:23:00 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_command	*cmd_new(int cmd_value)
// {
// 	t_command	*new_cmd;

// 	new_cmd = malloc(sizeof(t_command));
// 	if (!new_cmd)
// 		return (NULL);
// 	new_cmd->cmd_value = cmd_value;
// 	new_cmd->next = NULL;
// 	return (new_cmd);
// }

// int	cmd_add_back(t_command **cmd, t_command *new_cmd)
// {
// 	t_command	*current_cmd;

// 	if (!new_cmd || !cmd)
// 		return (EXIT_FAILURE);
// 	if (!*cmd)
// 		*cmd = new_cmd;
// 	else
// 	{
// 		current_cmd = *cmd;
// 		while (current_cmd->next)
// 			current_cmd = current_cmd->next;
// 		current_cmd->next = new_cmd;
// 	}
// 	return (EXIT_SUCCESS);
// }
