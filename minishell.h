/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:28:39 by jozefpluta        #+#    #+#             */
/*   Updated: 2025/03/30 18:26:04 by jozefpluta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_command
{
    char *command;
    t_command  *next;
}               t_command; 

/* --- main.c --- */
void    commands(char *input);
void    parse_data(char *input, t_command *commands);

/* --- utils.c --- */
int         ft_strcmp(const char *str1, const char *str2);
int         ft_strncmp(const char *s1, const char *s2, int n);
t_command   *create_commands();

/* --- commands_1.c --- */
