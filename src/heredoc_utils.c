/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:00:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/28 20:01:41 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	check_heredoc(void)
{
	char	pwd[1024];
	char	*heredoc_path;
	char	*cmd_line;
	int		parent;

	if (!getcwd(pwd, sizeof(pwd)))
		return ;
	heredoc_path = ft_strjoin(pwd, "/.heredoc");
	cmd_line = ft_strjoin("rm ", heredoc_path);
	if (!access(heredoc_path, F_OK))
	{
		parent = fork();
		if (!parent)
			execve("/usr/bin/rm", ft_split(cmd_line, ' '), NULL);
		else
			waitpid(-1, &global()->exit, 0);
	}
}

void	prepare_infile(t_tokens **tks, t_table **tab)
{
	free((*tab)->in_file);
	(*tab)->in_file = ft_strdup(".heredoc");
	(*tab)->in_red = TRUE;
	ft_lstfoward_free_t(tks);
}
