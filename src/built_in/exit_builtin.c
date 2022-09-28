/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:55:36 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/28 16:41:32 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	exit_builtin(t_table **tab)
{
	int	i;

	i = 0;
	rl_clear_history();
	while ((*tab)->cmd[i])
	{
		if (ft_isdigit((*tab)->cmd[i])
			|| ((*tab)->cmd[i] == '-' && ft_isdigit((*tab)->cmd[i + 1])))
		{
			global()->exit = ft_atoi((*tab)->cmd + i);
			exit (clean_exit(ft_strdup("cavalinho")));
		}
		i++;
	}
	clean_exit(ft_strdup("cavalinho"));
	exit (global()->exit);
}
