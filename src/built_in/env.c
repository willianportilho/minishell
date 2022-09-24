/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:54:46 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/23 23:11:07 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	env(t_table **tab, t_exec *exec)
{
	if (ft_array_str_len((*tab)->cmd_line) > 1)
	{
		ft_putstr_fd("minishell: env: this env take no options ", 2);
		ft_putstr_fd("or arguments\n", 2);
		return ;
	}
	else
		ft_array_print(global()->envp);
	if (exec->amount_cmd > 1)
		exit(0);
}
