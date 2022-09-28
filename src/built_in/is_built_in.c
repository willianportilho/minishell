/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:53:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/28 16:21:10 by ralves-b         ###   ########.fr       */
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

static void	reset_in_out(t_exec *exec)
{
	dup2(exec->cpin, 0);
	dup2(exec->cpout, 1);
	close(exec->cpin);
	close(exec->cpout);
}

static void	init_resources(t_table **tab, t_exec *exec)
{
	exec->cpin = dup(0);
	exec->cpout = dup(1);
	initialize_files(tab);
	check_infile(tab, exec);
	check_outfile(tab, exec);
}

static int	clean_builtin_child(t_exec *exec)
{
	pre_reset(*exec);
	clean_alloc(exec);
	rl_clear_history();
	return (clean_exit(ft_strdup("cavalinho")));
}

void	is_built_in(t_table **tab, t_exec *exec)
{
	exec->p = &global()->exit;
	if ((exec->amount_cmd == 1) && built_in_cmd((*tab)->cmd_line[0]))
		init_resources(tab, exec);
	if (ft_str_is_equal((*tab)->cmd_line[0], "echo"))
		*exec->p = echo(tab);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "cd"))
		*exec->p = cd(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "pwd"))
		*exec->p = pwd(tab, exec);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "export"))
		*exec->p = exportation(tab);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "unset"))
		*exec->p = unset(tab);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "env"))
		*exec->p = env(tab);
	else if (ft_str_is_equal((*tab)->cmd_line[0], "exit"))
		*exec->p = exit_builtin(tab);
	if ((exec->amount_cmd == 1) && built_in_cmd((*tab)->cmd_line[0]))
		reset_in_out(exec);
	if ((exec->amount_cmd > 1) && built_in_cmd((*tab)->cmd_line[0]))
		exit(clean_builtin_child(exec));
}
