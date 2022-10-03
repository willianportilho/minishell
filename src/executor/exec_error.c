/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:43:44 by wportilh          #+#    #+#             */
/*   Updated: 2022/10/04 04:21:39 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_file_and_not_permission(t_table **tab, t_exec *exec)
{
	struct stat	sb;
	int			status;

	status = stat((*tab)->cmd_line[0], &sb);
	if (!status && ((sb.st_mode & S_IFMT) == S_IFREG))
	{
		if (access((*tab)->cmd_line[0], X_OK)
			&& ft_strnstr((*tab)->cmd_line[0], "./", 2))
		{
			perror_message((*tab)->cmd_line[0]);
			clean_alloc(exec);
			rl_clear_history();
			global()->exit = 126;
			exit(clean_exit(ft_strdup("cavalinho")));
		}
	}
	return (0);
}

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
		if (ft_strlen(path) && !ft_strnstr((*tab)->cmd_line[0], "./", 2))
			str = ft_strjoin((*tab)->cmd_line[0], ": command not found\n");
		else
			str = ft_strjoin((*tab)->cmd_line[0], \
			": No such file or directory\n");
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(str, 2);
		free(path);
		free(str);
		global()->exit = 127;
	}
	clean_alloc(exec);
}
