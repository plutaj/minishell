/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:28:39 by jozefpluta        #+#    #+#             */
/*   Updated: 2025/04/19 16:15:23 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

/* --- tokens --- */

typedef enum e_token_type
{
    TOKEN_WORD,             // Command or argument: echo, ls, -l, /home, etc.
    TOKEN_PIPE,             // |
    TOKEN_REDIR_OUT,        // >
    TOKEN_REDIR_OUT_APPEND, // >>
    TOKEN_REDIR_IN,         // <
    TOKEN_HEREDOC,          // <<
    TOKEN_AND,              // &&
    TOKEN_OR,               // ||
    TOKEN_OPEN_PAREN,       // (
    TOKEN_CLOSE_PAREN,      // )
    TOKEN_NEWLINE,          // \n or end of input (optional, for parsing convenience)
    TOKEN_EOF,              // End of input/file
    TOKEN_INVALID           // Something unrecognized (good for error handling)
}   				t_token_type;

/* --- structs --- */
typedef struct s_token
{
	char 			*value;
	t_token_type	type;
}					t_token;

typedef struct s_data
{
	char	**env_var;
	char	*input;
	char	**cmd_line;
}				t_data;

/* --- minishell.c --- */
void	lexer(t_data *data);

/* --- enviromentals.c --- */
void	alloc_init_data(t_data *data, char **envp);
int		get_len_of_2d_array(char **array);
char	*is_env_var(char *input, char **envp);
void 	strncpy_until_char(char *dest, const char *src, char stop_char);

/* --- built_ins.c --- */

