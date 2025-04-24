/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:50:19 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/24 18:37:15 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Need to take care about cases like "<, >, >>, <<"
void	cmd_echo_exec(t_data *data, int is_newline)
{
	if (data->cmd_list && !is_newline)
		printf("%s", data->cmd_list->value);
	else if (data->cmd_list)
		printf("%s\n", data->cmd_list->value);
	// Plan
	// check_special_cases(data);
}

// void	check_special_cases(t_data *data)
// {
// 	int	redirection;
// 	int	quotes;

// 	redirection = 0;
// 	quotes = check_for_quotes(data);
// }