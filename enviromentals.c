/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviromentals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:09:04 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/20 17:10:01 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_len_of_2d_array(char **array)
{
	int len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

char	*is_env_var(char *input, char **envp)
{
	char	env_var[256];
	int		i;
	char	*result;
	
	i = 0;
	result = NULL;
	input++; // skip '$' sign
	strncpy_until_char(env_var, input, '=');
	while (envp[i])
	{
		if (strncmp(env_var, envp[i], strlen(env_var)) == 0)
		{
			result = strchr(envp[i], '=');
			if (result)
			{
				result++; // skip '=' sign
				return (result);
			}
		}
		i++;
	}
	return (NULL);
}

void strncpy_until_char(char *dest, const char *src, char stop_char)
{
    while (*src != '\0' && *src != stop_char)
	{
        *dest = *src;
        dest++; 
        src++;
    }
    *dest = '\0';
}