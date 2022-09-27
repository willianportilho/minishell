/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:53:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/27 14:39:31 by wportilh         ###   ########.fr       */
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
	exec->p = &global()->exit;
	exec->cpin = dup(0);
	exec->cpout = dup(1);
	initialize_files(tab);
	check_infile(tab, exec);
	check_outfile(tab, exec);
	if (ft_str_is_equal((*tab)->cmd_line[0], "echo"))
		*exec->p = echo(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "cd"))
		*exec->p = cd(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "pwd"))
		*exec->p = pwd(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "export"))
		*exec->p = exportation(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "unset"))
		*exec->p = unset(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "env"))
		*exec->p = env(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "exit"))
		*exec->p = exit_builtin(tab);
	dup2(exec->cpin, 0);
	dup2(exec->cpout, 1);
	close(exec->cpin);
	close(exec->cpout);
}
