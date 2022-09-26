/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:53:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/26 19:07:26 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	built_in_cmd(char *cmd)
{
	if ((ft_str_is_equal(cmd, "echo")
			|| ft_str_is_equal(cmd, "cd"))
		|| ft_str_is_equal(cmd, "pwd")
		|| ft_str_is_equal(cmd, "unset")
		|| ft_str_is_equal(cmd, "export")
		|| ft_str_is_equal(cmd, "exit")
		|| ft_str_is_equal(cmd, "env"))
	{
		return (1);
	}
	return (0);
}

void	is_built_in(t_table **tab, t_exec *exec)
{
	if (ft_str_is_equal((*tab)->cmd_line[0], "echo"))
		global()->exit = echo(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "cd"))
		global()->exit = cd(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "pwd"))
		global()->exit = pwd(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "unset"))
		global()->exit = unset(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "env"))
		global()->exit = env(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "exit"))
		global()->exit = exit_builtin(tab);
	if (exec->amount_cmd == 1 && built_in_cmd((*tab)->cmd_line[0]))
	{
		exec->amount_cmd--;
		exec->exit = 0;
	}
}
