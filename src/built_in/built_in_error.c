/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:27:56 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/23 04:53:00 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	built_in_error(t_exec *exec, char *cmd)
{
	char	*str;
	//char	*str2;
	str = ft_strjoin("minishell: ", cmd);
	//str2 = ft_strjoin(str, (*tab)->cmd_line[1]);
	perror(str);
	free(str);
	//free(str2);
	if (exec->amount_cmd > 1)
		exit(-1);
	else
		exec->exit = 0;
}
