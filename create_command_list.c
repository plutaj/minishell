/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:46:46 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/21 13:49:30 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_command_list(t_data *data)
{
	int		n;
	t_token	*new;
	t_token	*current;

	n = 0;
	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
	{
		printf("Error: Malloc failed\n");
		exit(1);
	}
	new->id = n;
	// new->value = ft_strdup(data->cmd_line[n]);
	new->value = data->cmd_line[n];
	new->type = get_token_type(data->cmd_line[n]);
	new->next = NULL;
	data->cmd_list = new;
	current = new;
	n++;
	if (!create_command_list2(n, new, data, current))
	{
		printf("ERROR: Malloc fail in 'create_command_list'\n");
		exit(1);
	}
	// return (1);
}

int	create_command_list2(int n, t_token *new, t_data *data, t_token *current)
{
	while (data->cmd_line[n])
	{
		new = (t_token *)malloc(sizeof(t_token));
		if (!new)
		{
			printf("Error: Malloc failed in 'create_command_list2'\n");
			return (0);
		}
		new->id = n;
		// new->value = ft_strdup(data->cmd_line[n]);
		new->value = data->cmd_line[n];
		new->type = get_token_type(data->cmd_line[n]);
		new->next = NULL;
		current->next = new;
		current = new;
		n++;
	}
	return (1);
}

t_token_type get_token_type(const char *str)
{
	if (!str)
		return TOKEN_INVALID;
	if (ft_strcmp(str, "|") == 0)
		return TOKEN_PIPE;
	else if (ft_strcmp(str, ">>") == 0)
		return TOKEN_REDIR_OUT_APPEND;
	else if (ft_strcmp(str, ">") == 0)
		return TOKEN_REDIR_OUT;
	else if (ft_strcmp(str, "<<") == 0)
		return TOKEN_HEREDOC;
	else if (ft_strcmp(str, "<") == 0)
		return TOKEN_REDIR_IN;
	else if (ft_strcmp(str, "&&") == 0)
		return TOKEN_AND;
	else if (ft_strcmp(str, "||") == 0)
		return TOKEN_OR;
	else if (ft_strcmp(str, "(") == 0)
		return TOKEN_OPEN_PAREN;
	else if (ft_strcmp(str, ")") == 0)
		return TOKEN_CLOSE_PAREN;
	else if (ft_strcmp(str, "\n") == 0)
		return TOKEN_NEWLINE;
	else if (ft_strcmp(str, "") == 0)
		return TOKEN_EOF;

	// Default: anything else is considered a WORD (like commands, args)
	return TOKEN_WORD;
}