/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:28:08 by jozefpluta        #+#    #+#             */
/*   Updated: 2025/04/26 14:57:56 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Only temporarry for printing type of tokens */
const char *token_type_to_string[] = {
    "TOKEN_WORD",             // 0
    "TOKEN_PIPE",             // 1
    "TOKEN_REDIR_OUT",        // 2
    "TOKEN_REDIR_OUT_APPEND", // 3
    "TOKEN_REDIR_IN",         // 4
    "TOKEN_HEREDOC",          // 5
    "TOKEN_NEWLINE",          // 6
    "TOKEN_EOF",              // 7
    "TOKEN_INVALID"           // 8
};

int main(int argc, char **argv, char **envp)
{
	t_data	data;
	
	(void)argc;
	(void)argv;
	if (argc != 1)
		return (printf("Error: Unexpected input.\n"));
	// Initializing all data like PATH, ENV and so ... rest to NULL
	init_data(&data, envp);
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
	// int i;

	// i = 0;
	if (!check_for_quotes(data))
	{
		printf("quote>\n");
		set_data_to_default(data);
		return ;
	}
	// split line to 2d array 
	data->cmd_line = ft_split(data->input, ' ');
	// Holds pointer to original cmd_linked list to free it later
	create_command_list(data);
	if (data->cmd_list)
		data->head_cmd_list = data->cmd_list;
	// just for check if storing correct data and token types*****************
	// t_token *cmd_list;
	// cmd_list = data->cmd_list;
	// // printf("CURRENT PATH: %s\n", data->current_path);
	// while (cmd_list)
	// {
	// 	printf("ID: %d\nVALUE: %s\nTOKEN: %s\n", cmd_list->id, cmd_list->value, token_type_to_string[cmd_list->type]);
	// 	cmd_list = cmd_list->next;
	// }
	// just for check if storing correct data and token types*****************
	is_cd_pwd_ls_exit(data);
	set_data_to_default(data);
}


