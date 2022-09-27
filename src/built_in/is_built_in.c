/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:53:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/26 21:57:13 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	built_in_cmd(char *cmd)
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
	int	*p;

	p = &global()->exit;
	if (ft_str_is_equal((*tab)->cmd_line[0], "echo"))
		*p = echo(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "cd"))
		*p = cd(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "pwd"))
		*p = pwd(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "export"))
		exportation(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "unset"))
		*p = unset(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "env"))
		*p = env(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "exit"))
		*p = exit_builtin(tab);
	if (exec->amount_cmd == 1 && built_in_cmd((*tab)->cmd_line[0]))
	{
		exec->amount_cmd--;
		exec->exit = 0;
	}
}
