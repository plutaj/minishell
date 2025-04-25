/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:57:55 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/25 18:40:24 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// This function will go through whole cmd-line and check if there is 
// even num of single or double quotes '' "";
int	check_for_quotes(t_data *data)
{
	const char	*line;
	int			single_quotes;	
	int			double_quotes;	
	
	line = data->input;
	single_quotes = 0;
	double_quotes = 0;
	while (*line)
	{
		if (*line == '\'')
			single_quotes++;
		if (*line == '\"')
			double_quotes++;
		line++;
	}
	if (single_quotes % 2 == 1 || double_quotes % 2 == 1)
		return (0);
	return (1);
}

void	free_2d_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_data(t_data *data)
{
	int i = 0;
    while (data->env && data->env[i]) {
        free(data->env[i]);
        i++;
    }
    free(data->env);
	data->env = NULL;
	if (data->current_path)
	{
		free(data->current_path);
		data->current_path = NULL;
	}
}