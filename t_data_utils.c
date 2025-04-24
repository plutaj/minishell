/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:41:33 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/24 16:35:33 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// initialize data for general data structure 
void	init_data(t_data *data, char **envp)
{
	data->env = copy_envp(envp); // set a env var 2d array
	data->input = NULL;
	data->cmd_line = NULL;
	get_path(data); // set a current path in data struct
	data->cmd_list = NULL;
}

void	get_path(t_data *data)
{
	char	*cwd;
    char	buffer[1024];

    cwd = getcwd(buffer, sizeof(buffer));
    if (cwd == NULL)
	{
		perror("getcwd() error");
		exit(1);
	}
	data->current_path = ft_strdup(cwd);
}

void	set_data_to_default(t_data *data)
{
	int		i;
	t_token *temp;

	i = 0;
	temp = data->head_cmd_list;
	while (data->head_cmd_list)
	{
		temp = data->head_cmd_list->next;
		free(data->head_cmd_list);
		data->head_cmd_list = temp;
	}
	data->head_cmd_list = NULL;
	data->cmd_list = NULL;
	if (data->input)
	{
		free (data->input);
		data->input = NULL;
	}
	if (data->cmd_line)
	{
		while (data->cmd_line[i])
		{
			free(data->cmd_line[i]);
			data->cmd_line[i] = NULL;
			i++;
		}
		free (data->cmd_line);
		data->cmd_line = NULL;
	}
}