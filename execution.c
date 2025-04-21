/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:56:33 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/21 16:00:13 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// temp function for testing purposes
void	is_cd_pwd_ls_exit(t_data *data)
{
	t_token	*cmd_list;

	cmd_list = data->cmd_list;
	// Goes throught a linked list and find for executable command
	while (cmd_list)
	{
		if (ft_strcmp(cmd_list->value, "pwd") == 0)
		{
			cmd_pwd(data);
		}
		if (ft_strcmp(cmd_list->value, "exit") == 0)
		{
			cmd_exit();
		}
		if (ft_strcmp(cmd_list->value, "ls") == 0)
		{
			cmd_ls(data->current_path);
		}
		cmd_list = cmd_list->next;
	}
}