/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportation_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 01:19:57 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/28 16:44:06 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	check_characters(char *cmd)
{
	int	i;

	i = -1;
	if ((!ft_isalpha(cmd[0])) && (cmd[0] != '_'))
	{
		built_in_identifier_error("export", cmd);
		return (0);
	}
	while (cmd[++i])
	{
		if (cmd[i] == '=')
			return (1);
		if ((!ft_isalnum(cmd[i])) && (cmd[i] != '_'))
		{
			built_in_identifier_error("export", cmd);
			return (0);
		}
	}
	return (1);
}

char	**array_remove_export(int i)
{
	char	**new_array;
	int		size;
	int		i_na;
	int		i_a;

	i_a = 0;
	i_na = 0;
	size = ft_array_str_len(global()->envp);
	new_array = (char **)malloc(size * sizeof(char *));
	while (i_a < size)
	{
		if (i_a == i)
			i_a++;
		if (i_a < size)
			new_array[i_na] = ft_strdup(global()->envp[i_a]);
		i_a++;
		i_na++;
	}
	new_array[size - 1] = NULL;
	ft_free_array(global()->envp);
	return (new_array);
}
