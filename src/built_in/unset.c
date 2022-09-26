/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:53:47 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/26 22:48:32 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	teste_exist(char **a, char *join)
{
	int	i_a;

	i_a = -1;
	while (a[++i_a])
	{
		if (ft_strnstr(a[i_a], join, ft_strlen(join)))
			return (1);
	}
	return (0);
}

char	**array_remove(char **a, char *new_str)
{
	char	**new_array;
	char	*join;
	int		i_na;
	int		i_a;

	join = ft_strjoin(new_str, "=");
	if (!teste_exist(a, join))
	{
		free(join);
		return (a);
	}
	new_array = (char **)malloc((ft_array_str_len(a)) * sizeof(char *));
	i_a = 0;
	i_na = 0;
	while (a[i_a])
	{
		if (ft_strnstr(a[i_a], join, ft_strlen(join)))
			i_a++;
		new_array[i_na] = ft_strdup(a[i_a]);
		i_a++;
		i_na++;
	}
	new_array[i_na] = NULL;
	ft_free_array(a);
	return (new_array);
}

static int	check_characters(char *cmd)
{
	int	i;
	int	size;

	i = -1;
	size = ft_strlen(cmd);
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

int	unset(t_table **tab, t_exec *exec)
{
	int		i;
	char	**temp_envp;

	i = 0;
	if (ft_array_str_len((*tab)->cmd_line) == 1)
		global()->exit = 0;
	else
	{
		while ((*tab)->cmd_line[++i])
		{
			if (check_characters((*tab)->cmd_line[i]))
			{
				temp_envp = array_remove(global()->envp, (*tab)->cmd_line[i]);
				global()->envp = temp_envp;
			}
			else
				global()->exit = 1;
		}
	}	
	if (exec->amount_cmd > 1)
		exit(global()->exit);
	return (global()->exit);
}
