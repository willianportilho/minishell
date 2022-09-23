/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:53:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/23 17:15:06 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	built_in_cmd(char *cmd)
{
	if ((ft_str_is_equal(cmd, "echo")
		|| ft_str_is_equal(cmd, "cd"))
		|| ft_str_is_equal(cmd, "pwd"))
		return (1);
	return (0);
}

void	is_built_in(t_table **tab, t_exec *exec, char **envp)
{
	if (ft_str_is_equal((*tab)->cmd_line[0], "echo"))
		echo(tab, exec);
	if (ft_str_is_equal((*tab)->cmd_line[0], "cd"))
		cd(tab, exec, envp);
	if (ft_str_is_equal((*tab)->cmd_line[0], "pwd"))
		pwd(tab, exec);
	if (exec->amount_cmd == 1 && built_in_cmd((*tab)->cmd_line[0]))
	{
		exec->amount_cmd--;
		exec->exit = 0;
	}
}
