/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:43:44 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/30 03:51:02 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	cmd_error(t_table **tab, t_exec *exec)
{
	char	*str;
	char	*str2;
	char	*path;

	path = simple_expander(ft_strdup("PATH"));
	if (ft_strlen(path))
		str = ft_strjoin((*tab)->cmd_line[0], ": command not found\n");
	else
		str = ft_strjoin((*tab)->cmd_line[0], ": No such file or directory\n");
	str2 = ft_strjoin("minishell: ", str);
	ft_putstr_fd(str2, 2);
	free(path);
	free(str);
	free(str2);
	clean_alloc(exec);
}
