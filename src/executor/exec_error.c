/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:43:44 by wportilh          #+#    #+#             */
/*   Updated: 2022/10/04 00:17:37 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_error_fd(char *msg, char *str, int fd, t_exec *exec)
{
	ft_putstr_fd("minishell: ", fd);
	ft_putstr_fd(str, fd);
	ft_putstr_fd(": ", fd);
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);
	exec->pos = -1;
}

void	perror_message(char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	perror(msg);
}

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
