/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:28:08 by jozefpluta        #+#    #+#             */
/*   Updated: 2025/04/01 19:22:53 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	t_data	data;
	char	*input;
	
	if (argc != 1)
		return (printf("Error: Unexpected input.\n"));
	alloc_init_data(&data, envp);
	while (1)
	{
		input = readline("minishell> ");
		if (strcmp(input, "exit") == 0)
		{
			printf("Exiting...\n");
			exit(0);
		}
		else if (strchr(input, '$'))
		{
			if (is_env_var(strchr(input, '$'), data.env_var))
				printf("minishell> %s\n", is_env_var(strchr(input, '$'), data.env_var));
		}
		free (input);
	}
    return (0);
}

void	alloc_init_data(t_data *data, char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = get_len_of_2d_array(envp);
	data->env_var = (char **)malloc(sizeof(char *) * (len + 1));
	while (envp[i])
	{
		if (!envp[i])
		{
			printf("Error: Malloc in *alloc_init_data envp[%d]* failed.\n", i);
			exit(1);
		}
		data->env_var[i] = (char *)malloc(strlen(envp[i]) + 1);
		strcpy(data->env_var[i], envp[i]);
		i++;
	}
	data->env_var[i] = NULL;
}

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