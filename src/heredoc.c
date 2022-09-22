/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:47:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/22 02:22:07 by ralves-b         ###   ########.fr       */
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
	char	*delimiter;

	(*tab)->in_delimiter = TRUE;
	(*tab)->infile_fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	(*tab)->in_file = ft_strdup(".heredoc");
	ft_lstfoward_free_t(tks);
	(*tab)->in_red = TRUE;
	delimiter = ft_strdup((*tks)->str);
	ft_lstfoward_free_t(tks);
	while ((*tab)->in_delimiter)
	{
		buf = readline(">");
		if (buf == NULL)
		{
			ft_printf("%s (wanted `%s')\n", HDERRO ,delimiter);
			(*tab)->in_delimiter = FALSE;
			break ;
		}
		if (ft_str_is_equal(buf, delimiter))
		{
			(*tab)->in_delimiter = FALSE;
			break ;
		}
		write((*tab)->infile_fd, buf, ft_strlen(buf));
		ft_putstr_fd("\n", (*tab)->infile_fd);
	}
	close((*tab)->infile_fd);
}
