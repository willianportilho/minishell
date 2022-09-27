/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:54:46 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/27 17:27:00 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	env(t_table **tab)
{
	int	i;

	i = -1;
	if (ft_array_str_len((*tab)->cmd_line) > 1)
	{
		ft_putstr_fd("minishell: env: this env take no options ", 2);
		ft_putstr_fd("or arguments\n", 2);
		global()->exit = 127;
	}
	else
	{
		if (!global()->envp || !(*global()->envp))
			return (global()->exit);
		while (global()->envp[++i])
		{
			if (ft_strlen_til_chr(global()->envp[i], '=') > 0)
				ft_printf("%s\n", global()->envp[i]);
		}
	}
	return (global()->exit);
}
