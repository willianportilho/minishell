/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:47:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/22 03:53:46 by ralves-b         ###   ########.fr       */
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
			waitpid(-1, NULL, 0);
	}
}

void	heredoc(t_tokens **tks, t_table **tab)
{
	char	*buf;

	(*tab)->in_delimiter = TRUE;
	global()->test = TRUE;
	global()->fd_global = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	signal(SIGINT, &handle_sigint_heredoc);
	while ((*tab)->in_delimiter && global()->test)
	{
		buf = readline(">");
		if (buf == NULL)
		{
			ft_printf("%s (wanted `%s')\n", HDERRO , (*tks)->str);
			(*tab)->in_delimiter = FALSE;
			break ;
		}
		if (ft_str_is_equal(buf, (*tks)->str))
		{
			(*tab)->in_delimiter = FALSE;
			break ;
		}
		write(global()->fd_global, buf, ft_strlen(buf));
		ft_putstr_fd("\n", global()->fd_global);
	}
	close(global()->fd_global);
	exit(0);
}

void	heredoc_caller(t_tokens **tks, t_table **tab)
{
	int	parent;
	int	vai_rolar_essa_merda;

	ft_lstfoward_free_t(tks);
	parent = fork();
	if (!parent)
	{
		heredoc(tks, tab);
	}
	else
	{
		waitpid(parent, &vai_rolar_essa_merda, 0);
		if (!vai_rolar_essa_merda)
		{
			(*tab)->in_file = ft_strdup(".heredoc");
			(*tab)->in_red = TRUE;
			global()->heredoc = FALSE;
			global()->test = FALSE;
			ft_lstfoward_free_t(tks);
		}
		(*tab)->heredoc_error = TRUE;
	}
}
