/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:12:09 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/25 17:37:55 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_echo(t_data *data)
{
    if (data->cmd_list && ft_strcmp(data->cmd_list->value, "-n") == 0)
    {
		data->cmd_list = data->cmd_list->next;
        cmd_echo_exec(data, 0);
    }
    else if (data->cmd_list)
        cmd_echo_exec(data, 1);
}

// void	cmd_cd(t_data *data)
// {
// 	t_token	*cmd_list;
// 	// char	path[256];

// 	cmd_list = data->cmd_list;
// 	if (ft_strcmp(data->cmd_list->value, "cd") == 0 && !data->cmd_list->next)
// 	{
// 		chdir(is_env_var("$HOME", data->env));
// 		data->current_path = is_env_var("$HOME", data->env);
// 	}
// 	else if (ft_strcmp(data->cmd_list->value, "cd"))
// 	{
// 		if (chdir(ft_strjoin(data->current_path, data->cmd_list->next->value)) == 0)
// 		{
// 			data->current_path = ft_strjoin(data->current_path, data->cmd_list->next->value);
// 			data->cmd_list = data->cmd_list->next;
// 		}
// 	}
// 	// else if (data->cmd_list->value == "cd" && data->cmd_list->next->value == "..")
// 	// {
		
// 	// }
// }

void	cmd_pwd(t_data *data)
{
	get_path(data);
	printf("%s\n", data->current_path);
}

void	cmd_exit(t_data *data)
{
	set_data_to_default(data);
	free_data(data);
	exit(0);
}

void	cmd_ls(const char *path)
{
    DIR 			*dir;
    struct dirent	*entry;
    char 			**entries;
    int 			count;
    int 			capacity;
	int				max_len;

	entries = NULL;
	count = 0;
	capacity = 10;
    dir = opendir(path);
    if (!dir)
	{
        perror("opendir");
        return;
    }
    entries = malloc(sizeof(char *) * capacity);
    if (!entries)
	{
        perror("malloc");
        closedir(dir);
        return;
    }
    while ((entry = readdir(dir)) != NULL)
	{
        // Skip hidden files (starting with .)
        if (entry->d_name[0] == '.')
            continue;

        if (count >= capacity) {
            capacity *= 2;
            entries = realloc(entries, sizeof(char *) * capacity);
            if (!entries) {
                perror("realloc");
                closedir(dir);
                return;
            }
        }
        entries[count++] = ft_strdup(entry->d_name); // Copy entry name
    }
    closedir(dir);
    // Sort entries alphabetically
    qsort(entries, count, sizeof(char *), compare);

    // Print entries space-separated
	max_len = get_max_len(entries, count) + 3;
	for (int i = 0; i < count; i++)
	{
		printf("%-*s", (int)max_len, entries[i]);
		free(entries[i]);
	}
    printf("\n");
    free(entries);
}