/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:00:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/03 20:08:36 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	child_heredoc(char *heredoc_path)
{
	char	*cmd_line;
	char	**cmd;

	cmd_line = ft_strjoin("rm ", heredoc_path);
	free(heredoc_path);
	cmd = ft_split_free(cmd_line, ' ');
	execve("/usr/bin/rm", cmd, NULL);
	ft_free_array(cmd);
}

void	check_heredoc(void)
{
	char	pwd[1024];
	char	*heredoc_path;
	int		parent;

	if (!getcwd(pwd, sizeof(pwd)))
		return ;
	heredoc_path = ft_strjoin(pwd, "/.heredoc");
	if (!access(heredoc_path, F_OK))
	{
		parent = fork();
		if (!parent)
		{	
			child_heredoc(heredoc_path);
		}
		else
		{
			waitpid(-1, &global()->exit, 0);
			free(heredoc_path);
		}
	}
	else
		free(heredoc_path);
}

void	prepare_infile(t_tokens **tks, t_table **tab)
{
	free((*tab)->in_file);
	(*tab)->in_file = ft_strdup(".heredoc");
	(*tab)->in_red = TRUE;
	ft_lstfoward_free_t(tks);
}
