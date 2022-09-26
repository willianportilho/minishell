/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:27:56 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/26 21:06:33 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	built_in_exportation_error(char *cmd)
{
	ft_printf("minishell: export: `%s': not a valid identifier\n", cmd);
	//return (1);
}

void	built_in_pwd_error(t_exec *exec)
{
	perror("minishell: pwd");
	if (exec->amount_cmd > 1)
		exit(-1);
	else
		exec->exit = 0;
}

void	built_in_cd_error(t_table **tab, t_exec *exec)
{
	char	*str;

	str = ft_strjoin("minishell: cd: ", (*tab)->cmd_line[1]);
	perror(str);
	free(str);
	if (exec->amount_cmd > 1)
		exit(-1);
	else
		exec->exit = 0;
}
