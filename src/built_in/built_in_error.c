/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:27:56 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/26 19:24:27 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	built_in_pwd_error(t_exec *exec)
{
	perror("minishell: pwd");
	if (exec->amount_cmd > 1)
		exit(0);
	return (0);
}

int	built_in_cd_error(t_table **tab, t_exec *exec)
{
	char	*str;

	str = ft_strjoin("minishell: cd: ", (*tab)->cmd_line[1]);
	perror(str);
	free(str);
	if (exec->amount_cmd > 1)
		exit(1);
	return (1);
}
