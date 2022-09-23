/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:52:22 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/23 17:09:32 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*get_home(char **envp)
{
	int		i;
	char	*home_expanded;

	i = -1;
	home_expanded = NULL;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "HOME=", 5))
		{
			home_expanded = ft_strdup(envp[i] + 5);
			break ;
		}
	}
	return (home_expanded);
}

void	cd(t_table **tab, t_exec *exec, char **envp)
{
	char	*home;

	home = get_home(envp);
	if (ft_str_is_equal((*tab)->cmd_line[0], "cd"))
	{
		if (ft_array_str_len((*tab)->cmd_line) > 2)
		{
			free(home);
			ft_putstr_fd("minishell: cd: too many arguments\n", 2);
			return ;
		}
		if ((*tab)->cmd_line[1])
		{
			if (chdir((*tab)->cmd_line[1]))
				built_in_cd_error(tab, exec);
		}
		else
		{
			if (chdir(home))
				built_in_cd_error(tab, exec);
		}
		free(home);
	}
	if (exec->amount_cmd > 1)
		exit(0);
}
