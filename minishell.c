/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:28:08 by jozefpluta        #+#    #+#             */
/*   Updated: 2025/04/19 16:43:21 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **envp)
{
	t_data	data;
	
	if (argc != 1)
		return (printf("Error: Unexpected input.\n"));
	alloc_init_data(&data, envp);
	while (1)
	{
		data.input = readline("minishell$ ");
		if (data.input)
			add_history(data.input);
		lexer(&data);
	}
    return (0);
}

void	lexer(t_data *data)
{
	int i;

	i = 0;
	data->cmd_line = ft_split(data->input, ' ');
	while (data->cmd_line[i])
	{
		printf("|%s|\n", data->cmd_line[i]);
		i++;
	}
}
