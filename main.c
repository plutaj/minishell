/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jozefpluta <jozefpluta@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 15:28:08 by jozefpluta        #+#    #+#             */
/*   Updated: 2025/03/30 18:35:28 by jozefpluta       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
    char *input;

    input = NULL;
    while (1)
    {
        input = readline("minishell> ");
        commands(input);
    }
    return (0);
}

void    commands(char *input)
{
    int valid;
    t_command  *commands;

    valid = -1;
    commands = create_commands();
    if (input == NULL)
        return ;
    parse_data(input, commands);
    // printf("You entered: %s\n", input);
    // // echo case
    // valid = ft_strncmp(input, "echo", 4);
    // ft_echo(input);
    // // exit case
    // valid = ft_strcmp(input, "exit");
    // if (valid == 0)
    // {
    //     free(input);
    //     exit(0);
    // }
}

// void    parse_data(char *input, t_command *commands)
// {
//     char    **temp_input;
//     int     i;

//     temp_input = ft_split(input, ' ');
//     i = 0;
//     while (temp_input[i])
//     {
//         if (ft_strncmp(temp_input, "echo", 4) == 0)
//         i++;
//     }
// }