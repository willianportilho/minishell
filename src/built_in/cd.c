/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:52:22 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/23 21:43:45 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	cd(t_table **tab, t_exec *exec)
{
	char	*home;

	home = simple_expander("HOME");
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
