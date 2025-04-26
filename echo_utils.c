/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:50:19 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/26 16:03:52 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Need to take care about cases like "<, >, >>, <<, $, |"
void	cmd_echo_exec(t_data *data, int is_newline)
{
	char	*str_after_echo;

	str_after_echo = convert_to_string(data);
	// case with -n
	if (str_after_echo && !is_newline)
		printf("%s", str_after_echo);
	else if (str_after_echo)
		printf("%s\n", str_after_echo);
	free (str_after_echo);
}

char *convert_to_string(t_data *data)
{
	char	*orig_str;
	char	*temp;
	char	*str;

	orig_str = NULL;
	temp = NULL;
	while (data->cmd_list)
	{
		if (dollar_sign(data->cmd_list->value))
		{
			if ((str = is_env_var(data->cmd_list->value, data->env)) != NULL) // ! add to compare not only agains a env vars but also agains own variables
			{
				if (!orig_str)
					orig_str = ft_strdup(str);
				else
				{
					temp = ft_strjoin(orig_str, " ");
					free(orig_str);
					orig_str = ft_strjoin(temp, str);
					free(temp);
				}
			}
		}
		else if (orig_str == NULL && data->cmd_list->type == 0)
			orig_str = ft_strdup(data->cmd_list->value);
		else if (data->cmd_list->type == 0) // check for only WORD tokens
		{
			temp = ft_strjoin(orig_str, " ");
			free(orig_str);
			orig_str = ft_strjoin(orig_str, data->cmd_list->value);
			free(temp);
		}
		data->cmd_list = data->cmd_list->next;
	}
	return (orig_str);
}

int	dollar_sign(char *str)
{
	if (*str == '$')
		return (1);
	return (0);
}

