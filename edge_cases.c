/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 13:57:55 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/20 14:25:14 by jpluta           ###   ########.fr       */
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