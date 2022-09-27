/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:03:36 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/27 17:20:49 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	pwd(t_table **tab, t_exec *exec)
{
	char	cwd[4096];

	if (ft_str_is_equal((*tab)->cmd_line[0], "pwd"))
	{
		if (!getcwd(cwd, sizeof(cwd)))
			global()->exit = built_in_pwd_error(exec);
		ft_printf("%s\n", cwd);
	}
	return (global()->exit);
}
