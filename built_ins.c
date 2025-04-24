/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:12:09 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/24 19:25:45 by jpluta           ###   ########.fr       */
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

void cmd_cd(t_data *data)
{
	char *new_path;
	data->cmd_list = data->cmd_list->next;

	if (!data->cmd_list)
	{
		chdir(is_env_var("$HOME", data->env));
		free(data->current_path);
		data->current_path = ft_strdup(is_env_var("$HOME", data->env));
	}
	else if (ft_strcmp(data->cmd_list->value, ".."))
	{
		if (data->current_path && data->current_path[0] != '\0')
            {
                // Remove the last directory from current_path
                char *last_slash = strrchr(data->current_path, '/');
                if (last_slash && last_slash != data->current_path)
                {
                    // Create a new path that excludes the last directory
                    *last_slash = '\0';  // Null-terminate the path at the last slash
                }

                new_path = ft_strdup(data->current_path);  // Copy the updated path
                if (chdir(new_path) == 0)
                {
                    free(data->current_path);  // Free old path
                    data->current_path = new_path;  // Update current path
                }
                else
                {
                    // Handle chdir error
                    perror("minishell: cd");
                    free(new_path);  // Free new_path if chdir fails
                }
            }
	}
	// else
	// {
	// 	path = ft_strjoin(data->current_path, data->cmd_list->value);
	// 	while ()
	// }	
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

int	list_directory_contents(t_data *data, const char *path)
{
    struct dirent	*entry;
    DIR 			*dp;
	
	dp = opendir(path);
    if (dp == NULL)
	{
        perror("opendir");
        exit(1);
    }
    while ((entry = readdir(dp)) != NULL)
	{
        if (ft_strcmp(data->cmd_list->value, entry->d_name) == 0)
			return (1);
    }
    closedir(dp);
	return (0);
}

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