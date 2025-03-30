/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:38:17 by jozefpluta        #+#    #+#             */
/*   Updated: 2025/03/30 18:24:27 by jozefpluta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strcmp(const char *str1, const char *str2)
{
    while (*str1 && *str2) {
        if (*str1 != *str2)
            return (unsigned char)*str1 - (unsigned char)*str2;
        str1++;
        str2++;
    }
    return (unsigned char)*str1 - (unsigned char)*str2;
}

int ft_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        i++;
    }
    if (i < n)
        return (unsigned char)s1[i] - (unsigned char)s2[i];
    return 0;
}

t_command   *create_commands()
{
    t_command   *commands;
    
    commands = (t_command *)malloc(sizeof(t_command));
    if (!commands)
    {
        printf("Malloc in ---t_command   *create_commands()--- failed");
        exit(1);
    }
    commands->command = NULL;
    commands->next = NULL;
    return (commands);
}