/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:56:33 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/21 20:35:15 by jozefpluta       ###   ########.fr       */
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
		else if (ft_strcmp(cmd_list->value, "exit") == 0)
		{
			cmd_exit();
		}
		else if (ft_strcmp(cmd_list->value, "ls") == 0)
		{
			cmd_ls(data->current_path);
		}
		else if (ft_strcmp(cmd_list->value, "env") == 0)
		{
			print_env(data->env);
		}
		else if (ft_strcmp(cmd_list->value, "echo") == 0)
		{
			cmd_echo(cmd_list);
		}
		else
		{
			printf("minishell: %s command not found\n", cmd_list->value);
		}
		cmd_list = cmd_list->next;
	}
}