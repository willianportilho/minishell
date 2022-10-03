/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:43:44 by wportilh          #+#    #+#             */
/*   Updated: 2022/10/03 23:33:27 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	cmd_error(t_table **tab, t_exec *exec)
{
	char		*str;
	char		*str2;
	char		*path;
	struct stat	sb;

	if (!stat((*tab)->cmd_line[0], &sb) && ((sb.st_mode & S_IFMT) == S_IFDIR)
		&& ft_strchr((*tab)->cmd_line[0], '/'))
		global()->exit = 126;
	else if ((*tab)->cmd_line[0][0] == '/')
		global()->exit = 127;
	else
	{
		path = simple_expander(ft_strdup("PATH"));
		if (ft_strlen(path))
			str = ft_strjoin((*tab)->cmd_line[0], ": command not found\n");
		else
			str = ft_strjoin((*tab)->cmd_line[0], \
			": No such file or directory\n");
		str2 = ft_strjoin("minishell: ", str);
		ft_putstr_fd(str2, 2);
		free(path);
		free(str);
		free(str2);
		global()->exit = 127;
	}
	clean_alloc(exec);
}
