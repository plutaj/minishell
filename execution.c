/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:56:33 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/26 14:00:54 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// temp function for testing purposes
void	is_cd_pwd_ls_exit(t_data *data)
{
	// Goes throught a linked list and find for executable command
	while (data->cmd_list)
	{
		if (ft_strcmp(data->cmd_list->value, "pwd") == 0)
		{
			cmd_pwd(data);
		}
		else if (ft_strcmp(data->cmd_list->value, "exit") == 0)
		{
			cmd_exit(data);
		}
		else if (ft_strcmp(data->cmd_list->value, "ls") == 0)
		{
			cmd_ls(data->current_path);
		}
		else if (ft_strcmp(data->cmd_list->value, "env") == 0)
		{
			print_env(data->env);
		}
		else if (ft_strcmp(data->cmd_list->value, "echo") == 0)
		{
			data->cmd_list = data->cmd_list->next;
			cmd_echo(data);
		}
		else if (ft_strcmp(data->cmd_list->value, "cd") == 0)
		{
			cmd_cd(data);
			return ;
		}
		else
		{
			printf("%s: command not found\n", data->cmd_list->value);
		}
		if (data->cmd_list)
			data->cmd_list = data->cmd_list->next;
	}
}