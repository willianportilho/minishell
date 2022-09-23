/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:03:36 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/23 04:41:41 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	pwd(t_table **tab, t_exec *exec)
{
	char	cwd[1024];

	if (ft_str_is_equal((*tab)->cmd_line[0], "pwd"))
	{
		if (!getcwd(cwd, sizeof(cwd)))
			built_in_error(exec, "pwd");
		ft_printf("%s\n", cwd);
	}
	if (exec->amount_cmd > 1)
		exit(0);
	else
	{
		exec->amount_cmd--;
		exec->exit = 0;
	}
}
