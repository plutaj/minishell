/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:28:39 by jozefpluta        #+#    #+#             */
/*   Updated: 2025/04/21 18:10:50 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"

typedef struct s_data		t_data;
typedef struct s_token		t_token;
typedef enum e_token_type	t_token_type;

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
	int				id;
	char 			*value;
	t_token_type	type;
	t_token			*next;
}				t_token;

/* This structure holds all general data about a shell */
typedef struct s_data
{
	char	**env;
	char	*input;
	char	**cmd_line;
	char	*current_path;
	t_token	*cmd_list;
}				t_data;

/* --- minishell.c --- */
void			lexer(t_data *data);

/* --- enviromentals.c --- */
char			**copy_envp(char **envp);
int				get_len_of_2d_array(char **array);
char			*is_env_var(char *input, char **envp);
void			strncpy_until_char(char *dest, const char *src, char stop_char);
void			print_env(char **envp);
void			set_env_var(char ***envp, const char *var_name, const char *var_value);
// int				get_len_of_2d_array(char **array);
// char			*is_env_var(char *input, char **envp);
// void 			strncpy_until_char(char *dest, const char *src, char stop_char);

/* --- built_ins.c --- */
void			cmd_pwd(t_data *data);
void			cmd_exit();
// void			cmd_cd(t_data *data);
void			cmd_ls(const char *path);

/* --- t_data_utils.c --- */
void			init_data(t_data *data, char **envp);
void			get_path(t_data *data);
void			set_data_to_default(t_data *data);

/* --- edge_cases.c --- */
int				check_for_quotes(t_data *data);

/* --- create_command_list.c --- */
void			create_command_list(t_data *data);
int				create_command_list2(int n, t_token *new, t_data *data, t_token *current);
t_token_type	get_token_type(const char *str);

/* --- execution.c --- */
void			is_cd_pwd_ls_exit(t_data *data);

/* --- cmd_ls_utils.c --- */
int				get_max_len(char **entries, int count);
int				compare(const void *a, const void *b);
