/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 06:16:35 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/22 15:24:46 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	cd(t_table **tab)
{
	char s[100];

	if (ft_str_is_equal((*tab)->cmd_line[0], "cd"))
	{
		ft_printf("%s\n", getcwd(s, 100));
		chdir("");
		ft_printf("%s\n", getcwd(s, 100));
	}
	exit(0);
}
