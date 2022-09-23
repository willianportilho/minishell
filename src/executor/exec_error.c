/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:43:44 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/22 18:59:24 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	cmd_error(t_table **tab, t_exec *exec)
{
	char	*str;
	char	*str2;

	str = ft_strjoin((*tab)->cmd_line[0], ": command not found\n");
	str2 = ft_strjoin("minishell: ", str);
	ft_putstr_fd(str2, 2);
	free(str);
	free(str2);
	clean_alloc(exec);
}
