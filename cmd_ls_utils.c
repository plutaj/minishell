/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_ls_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpluta <jpluta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:28:14 by jpluta            #+#    #+#             */
/*   Updated: 2025/04/21 16:30:27 by jpluta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_max_len(char **entries, int count)
{
	int max = 0;
	for (int i = 0; i < count; i++)
	{
		int len = ft_strlen(entries[i]);
		if (len > max)
			max = len;
	}
	return max;
}

int compare(const void *a, const void *b)
{
    return strcoll(*(const char **)a, *(const char **)b);
}