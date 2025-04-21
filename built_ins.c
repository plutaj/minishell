/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:12:09 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/21 17:03:43 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	cmd_echo()
// {
	
// }

// void	cmd_cd(t_data *data)
// {
// 	if (data->cmd_list->value == "cd")
// 	{
		
// 	}
// 	else if (data->cmd_list->value == "cd" && data->cmd_list->next->value == "..")
// 	{
		
// 	}
// }

void	cmd_pwd(t_data *data)
{
	get_path(data);
	printf("%s\n", data->current_path);
}

void	cmd_exit()
{
	// There will be a function for freeing all allocated space
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