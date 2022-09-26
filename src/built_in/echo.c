/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:08:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/26 19:06:38 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	echo(t_table **tab, t_exec *exec)
{
	int	i;

	i = 0;
	if ((ft_str_is_equal((*tab)->cmd_line[i], "echo")) && (*tab)->cmd_line[++i])
	{
		if (ft_str_is_equal((*tab)->cmd_line[i], "-n"))
			i++;
		while ((*tab)->cmd_line[i])
		{
			if ((*tab)->cmd_line[i] && (!(*tab)->cmd_line[i + 1]))
				ft_printf("%s", (*tab)->cmd_line[i++]);
			else
				ft_printf("%s ", (*tab)->cmd_line[i++]);
		}
		if (!(ft_str_is_equal((*tab)->cmd_line[1], "-n")))
			ft_printf("\n");
	}
	else
		ft_printf("\n");
	if (exec->amount_cmd > 1)
		exit(0);
	return (0);
}
