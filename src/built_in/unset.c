/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:53:47 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/28 17:10:12 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	teste_exist(char **a, char *str)
{
	int	i_a;
	int	size;

	i_a = -1;
	size = ft_strlen(str);
	while (a[++i_a])
	{
		if (ft_strnstr(a[i_a], str, size) \
		&& ((!a[i_a][size]) || (a[i_a][size] == '=')))
			return (1);
	}
	return (0);
}

char	**array_remove(char **a, char *new_str)
{
	char	**new_array;
	int		size;
	int		i_na;
	int		i_a;

	if (!teste_exist(a, new_str))
		return (a);
	i_a = 0;
	i_na = 0;
	size = ft_strlen(new_str);
	new_array = (char **)malloc(ft_array_str_len(a) * sizeof(char *));
	while (a[i_a])
	{
		if (ft_strnstr(a[i_a], new_str, size) \
		&& ((!a[i_a][size]) || (a[i_a][size] == '=')))
			i_a++;
		if (a[i_a])
			new_array[i_na] = ft_strdup(a[i_a]);
		if (a[i_a])
			i_a++;
		i_na++;
	}
	new_array[ft_array_str_len(a) - 1] = NULL;
	ft_free_array(a);
	return (new_array);
}

static int	check_unset_characters(char *cmd)
{
	int	i;

	i = -1;
	if ((!ft_isalpha(cmd[0])) && (cmd[0] != '_'))
	{
		built_in_identifier_error("unset", cmd);
		return (0);
	}
	while (cmd[++i])
	{
		if ((!ft_isalnum(cmd[i])) && (cmd[i] != '_'))
		{
			built_in_identifier_error("unset", cmd);
			return (0);
		}
	}
	return (1);
}

int	unset(t_table **tab)
{
	int		i;
	char	**temp_envp;

	i = 0;
	global()->exit = 0;
	if (ft_array_str_len((*tab)->cmd_line) > 1)
	{
		while ((*tab)->cmd_line[++i])
		{
			if (check_unset_characters((*tab)->cmd_line[i]))
			{
				temp_envp = array_remove(global()->envp, (*tab)->cmd_line[i]);
				global()->envp = temp_envp;
			}
			else
				global()->exit = 1;
		}
	}
	return (global()->exit);
}
