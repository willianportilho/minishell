/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:52:22 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/26 22:30:22 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	cd_arguments_error(void)
{
	ft_putstr_fd("minishell: cd: too many arguments\n", 2);
	global()->exit = 1;
}

int	cd(t_table **tab, t_exec *exec)
{
	int		*p;
	char	*home;

	p = &global()->exit;
	home = simple_expander("HOME");
	if (ft_str_is_equal((*tab)->cmd_line[0], "cd"))
	{
		if (ft_array_str_len((*tab)->cmd_line) > 2)
			cd_arguments_error();
		else if ((*tab)->cmd_line[1])
		{
			if (chdir((*tab)->cmd_line[1]))
				*p = built_in_cd_error(tab, exec);
		}
		else
		{
			if (chdir(home))
				*p = (built_in_cd_error(tab, exec));
		}
		free(home);
	}
	if (exec->amount_cmd > 1)
		exit(global()->exit);
	return (global()->exit);
}
