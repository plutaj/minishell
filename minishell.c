/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:28:08 by jozefpluta        #+#    #+#             */
/*   Updated: 2025/04/20 18:18:16 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char *token_type_to_string[] = {
    "TOKEN_WORD",             // 0
    "TOKEN_PIPE",             // 1
    "TOKEN_REDIR_OUT",        // 2
    "TOKEN_REDIR_OUT_APPEND", // 3
    "TOKEN_REDIR_IN",         // 4
    "TOKEN_HEREDOC",          // 5
    "TOKEN_AND",              // 6
    "TOKEN_OR",               // 7
    "TOKEN_OPEN_PAREN",       // 8
    "TOKEN_CLOSE_PAREN",      // 9
    "TOKEN_NEWLINE",          // 10
    "TOKEN_EOF",              // 11
    "TOKEN_INVALID"           // 12
};

int main(int argc, char **argv)
{
	t_data	data;
	
	(void)argc;
	(void)argv;
	if (argc != 1)
		return (printf("Error: Unexpected input.\n"));
	init_data(&data); // add envp
	while (1)
	{
		data.input = readline("minishell$ ");
		if (data.input)
			add_history(data.input);
		lexer(&data);
	}
    return (0);
}

void	*lexer(t_data *data)
{
	int i;

	i = 0;
	if (!check_for_quotes(data))
	{
		printf("quote>\n");
		set_data_to_default(data);
		return (NULL);
	}
	data->cmd_line = ft_split(data->input, ' ');
	// while (data->cmd_line[i])
	// {
	// 	printf("|%s|\n", data->cmd_line[i]);
	// 	i++;
	// }
	create_command_list(data);
	t_token *cmd_list;
	cmd_list = data->cmd_list;
	while (cmd_list)
	{
		printf("ID: %d\nVALUE: %s\nTOKEN: %s\n", cmd_list->id, cmd_list->value, token_type_to_string[cmd_list->type]);
		cmd_list = cmd_list->next;
	}
	return (NULL);
}

void	init_data(t_data *data)
{
	data->env_var = NULL;
	data->input = NULL;
	data->cmd_line = NULL;
	data->cmd_list = NULL;
}

void	set_data_to_default(t_data *data)
{
	int i;

	i = 0;
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
	// if (*(data->cmd_line))
	// {
	// 	free (data->cmd_line);
	// 	data->cmd_line = NULL;
	// }
}
// 	if (data->cmd_line)
// 	{
// 		while (data->cmd_line[i])
// 			free(data->cmd_line[i++]);
// 		free (data->cmd_line);
// 		data->cmd_line = NULL;
// 	}
// }

