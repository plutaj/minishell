/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviromentals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:09:04 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/21 18:13:28 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Create our own env 2d array
char **copy_envp(char **envp)
{
    int i = 0;
    int count = 0;
    char **env;

    // Count how many environment variables there are
    while (envp[count])
        count++;
    // Allocate memory for your own environment array (+1 for NULL terminator)
    env = malloc(sizeof(char *) * (count + 1));
    if (!env)
    {
        perror("malloc");
        return NULL;
    }

    // Copy each string
    while (i < count)
    {
        env[i] = ft_strdup(envp[i]);
        if (!env[i])
        {
            perror("strdup");
            // Free everything if one strdup fails
            while (--i >= 0)
                free(env[i]);
            free(env);
            return NULL;
        }
        i++;
    }
    env[i] = NULL; // NULL-terminate the array
    return env;
}

int get_len_of_2d_array(char **array)
{
    int len = 0;
    while (array[len])
        len++;
    return len;
}

// Function to extract the value of an environment variable from the input
char *is_env_var(char *input, char **envp)
{
    char env_var[256];
    int i;
    char *result;

    i = 0;
    result = NULL;
    input++; // skip '$' sign
    strncpy_until_char(env_var, input, '=');
    while (envp[i])
	{
        if (ft_strncmp(env_var, envp[i], ft_strlen(env_var)) == 0)
		{
            result = ft_strchr(envp[i], '=');
            if (result)
			{
                result++; // skip '=' sign
                return result;
            }
        }
        i++;
    }
    return NULL;
}

// Function to copy characters until a specific character is found
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

// Function to set an environment variable in the char **env array
void set_env_var(char ***envp, const char *var_name, const char *var_value)
{
    // Get the current size of the environment variables
    int len = get_len_of_2d_array(*envp);

    // Reallocate memory for the new environment variable
    *envp = realloc(*envp, sizeof(char *) * (len + 2));
    if (!*envp)
	{
        perror("realloc");
        return;
    }
    // Allocate memory for the new variable string (name=value)
    size_t size = ft_strlen(var_name) + ft_strlen(var_value) + 2; // +2 for '=' and '\0'
    (*envp)[len] = malloc(size);
    if (!(*envp)[len])
	{
        perror("malloc");
        return;
    }
    // Create the "name=value" string
    snprintf((*envp)[len], size, "%s=%s", var_name, var_value);

    // Null-terminate the array
    (*envp)[len + 1] = NULL;
}

// Function to print the environment variables
void	print_env(char **envp)
{
    int i = 0;
    while (envp[i]) {
        printf("%s\n", envp[i]);
        i++;
    }
}