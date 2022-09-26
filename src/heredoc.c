/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:47:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/26 17:53:10 by ralves-b         ###   ########.fr       */
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

static void	heredoc_loop(t_tokens **tks)
{
	char	*buf;

	while (global()->test)
	{
		if (global()->test)
			buf = readline(">");
		if (buf == NULL)
		{
			ft_printf("%s (wanted `%s')\n", HDERRO, (*tks)->str);
			global()->test = FALSE;
			break ;
		}
		if (ft_str_is_equal(buf, (*tks)->str))
		{
			global()->test = FALSE;
			break ;
		}
		ft_putstr_fd(buf, global()->fd_global);
		ft_putstr_fd("\n", global()->fd_global);
	}
}

static void	heredoc(t_tokens **tks)
{
	int		fd;

	global()->test = TRUE;
	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	global()->fd_global = fd;
	heredoc_loop(tks);
	close(global()->fd_global);
	exit(global()->exit);
}

void	heredoc_caller(t_tokens **tks, t_table **tab)
{
	int	parent;

	ft_lstfoward_free_t(tks);
	parent = fork();
	if (!parent)
		heredoc(tks);
	else
	{
		wait(&global()->exit);
		if (!global()->exit)
		{
			(*tab)->in_file = ft_strdup(".heredoc");
			(*tab)->in_red = TRUE;
			ft_lstfoward_free_t(tks);
		}
		else
		{
			ft_lstclear_t(tab);
			*tab = malloc(sizeof(t_table));
			minishell(tab);
		}
	}
}
