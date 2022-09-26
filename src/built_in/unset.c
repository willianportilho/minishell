/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:53:47 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/26 05:04:40 by wportilh         ###   ########.fr       */
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

void	unset(t_table **tab, t_exec *exec)
{
	char	**temp_envp;

	temp_envp = array_remove(global()->envp, (*tab)->cmd_line[1]);
	global()->envp = temp_envp;
	if (exec->amount_cmd > 1)
		exit(0);
}
