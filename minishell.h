/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:28:39 by jozefpluta        #+#    #+#             */
/*   Updated: 2025/04/01 18:55:20 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_data
{
	char	**env_var;
}				t_data;

/* --- main.c --- */
void	alloc_init_data(t_data *data, char **envp);
int		get_len_of_2d_array(char **array);
char	*is_env_var(char *input, char **envp);
void	strncpy_until_char(char *dest, const char *src, char stop_char);
