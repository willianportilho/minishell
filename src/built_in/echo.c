/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:08:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/22 05:52:26 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	echo(t_table **tab)
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
	exit(0);
}
