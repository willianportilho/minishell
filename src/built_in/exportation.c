/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:48:23 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/23 23:18:25 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exportation(t_table **tab, t_exec *exec)
{
	int	i;

	i = 0;
	if (tab && exec)
		;
	if (global()->envp)
	{
		if (ft_array_str_len((*tab)->cmd_line) == 1)
		{
			while (global()->envp[i])
				ft_printf("%s\n", global()->envp[i++]);
		}
	}
}