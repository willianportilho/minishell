/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:47:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/29 19:00:02 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	prepare_new_loop(char **buf)
{
	expand(buf);
	bring_temp_values_back(buf);
	ft_putstr_fd(*buf, global()->fd_global);
	ft_putstr_fd("\n", global()->fd_global);
	free(*buf);
}

static void	first_loop(t_tokens **tks)
{
	free(global()->tabble->cmd);
	global()->tabble->cmd = ft_strdup((*tks)->str);
	clear_tokens_lst(tks);
	*tks = NULL;
}

static void	heredoc_loop(t_tokens **tks)
{
	char	*buf;

	while (global()->test)
	{
		if ((*tks))
			first_loop(tks);
		if (global()->test)
			buf = readline(">");
		if (buf == NULL)
		{
			ft_printf("%s (wanted `%s')\n", HDERRO, global()->tabble->cmd);
			free(buf);
			global()->test = FALSE;
			break ;
		}
		if (ft_str_is_equal(buf, global()->tabble->cmd))
		{
			global()->test = FALSE;
			free(buf);
			break ;
		}
		prepare_new_loop(&buf);
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
	rl_clear_history();
	global()->exit = 0;
	exit(clean_exit(ft_strdup("cavalinho")));
}

void	heredoc_caller(t_tokens **tks, t_table **tab)
{
	int	parent;

	ft_lstfoward_free_t(tks);
	if (!(*tks))
	{
		tkn_error(tks);
		return ;
	}
	parent = fork();
	if (!parent)
		heredoc(tks);
	else
	{
		wait(&parent);
		if (!parent)
			prepare_infile(tks, tab);
		else
		{
			pre_reset();
			reset_tab(ft_strdup("cavalinho"));
			global()->control = FALSE;
			minishell(&global()->tabble);
		}
	}
}
