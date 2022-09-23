/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_built_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:53:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/23 15:07:43 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	is_built_in(t_table **tab, t_exec *exec, char **envp)
{
	if (ft_str_is_equal((*tab)->cmd_line[0], "echo"))
		echo(tab, exec);
	if (ft_str_is_equal((*tab)->cmd_line[0], "cd"))
		cd(tab, exec, envp);
	if (ft_str_is_equal((*tab)->cmd_line[0], "pwd"))
		pwd(tab, exec);
}
